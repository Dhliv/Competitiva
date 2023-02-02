#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ull unsigned long long
#define ld long double
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define PI 3.14159265358979323846
#define MAX 1000001
 
using namespace std;
 
const ld EPSILON = 0.0000001;
int trie[MAX][26];
int nodes = 0;
int fin[MAX], mini[MAX], fail[MAX];
int fin_fin[MAX];

void add(string &s, int idx){
  int cur = 0;
  int x;

  for(const char &c: s){
    x = c - 'a';

    if(!trie[cur][x]){
      trie[cur][x] = ++nodes;
      mini[trie[cur][x]] = idx;
    }
    cur = trie[cur][x];
  }

  fin[cur] = fin[cur] ? fin[cur] : idx;
}

void build(){
  int x, y;

  deque<int> q;
  q.PB(0);

  while(!q.empty()){
    x = q.F(); q.P_F();

    FOR(i, 0, 26){
      y = trie[x][i];

      if(y) q.PB(y);
      else trie[x][i] = trie[fail[x]][i];

      if(!y or !x) continue;

      fail[y] = trie[fail[x]][i];
      fin_fin[y] = fin[fail[y]] ? fail[y] : fin_fin[fail[y]];
    }
  }
}

bool look(int &idx, string &s){
  int cur = 0;
  int x;

  for(const char &c: s){
    x = c - 'a';

    cur = trie[cur][x];
    while(cur and mini[cur] > idx){
      if(fin_fin[cur] and fin[fin_fin[cur]] <= idx) return true;
      cur = fail[cur];
    }

    if(fin[cur] and fin[cur] <= idx) return true;
    if(fin_fin[cur] and fin[fin_fin[cur]] <= idx) return true;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;

  FOR(i, 0, MAX){
    fin_fin[i] = fin[i] = fail[i] = 0;
    mini[i] = INF;

    FOR(j, 0, 26) trie[i][j] = 0;
  }

  int t;
  string s;
  vector<pair<int, string> > qr;

  FOR(i, 0, n){
    cin >> t >> s;
    if(t) qr.PB(MP(i + 1, s));
    else add(s, i + 1);
  }

  build();

  FOR(i, 0, qr.size()){
    cout << (look(qr[i].f, qr[i].s) ? "YES" : "NO") << "\n";
  }
 
  return 0;
}