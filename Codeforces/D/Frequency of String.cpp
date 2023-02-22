#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
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
#define MAX 100005
 
using namespace std;
 
const ld EPSILON = 0.0000001;

struct dt{
  int k, id;
  string s;

  dt(){}
  dt(int &k, int &id, string &s) : k(k), id(id), s(s){}
};

int trie[MAX][26], nds = 1;
int fin[MAX], fail[MAX], sure_fail[MAX];
vector<int> mini;
vector<deque<int> > pos;
vector<dt> ids;
vector<dt> needs;

int add(string &s){
  int cr = 0, x;

  for(const auto &c: s){
    x = c - 'a';

    if(trie[cr][x] == 0) trie[cr][x] = nds++;
    cr = trie[cr][x];
  }

  fin[cr] = 1;
  return cr;
}

void build(){
  int x, cr = 0;

  deque<int> q;
  q.PB(cr);

  while(!q.empty()){
    cr = q.F(); q.P_F();

    FOR(i, 0, 26){
      x = trie[cr][i];
      if(x) q.PB(x);

      if(cr == 0) continue;
      if(x == 0){
        trie[cr][i] = trie[fail[cr]][i];
        continue;
      }

      fail[x] = trie[fail[cr]][i];
      sure_fail[x] = fin[fail[x]] ? fail[x] : sure_fail[fail[x]];
    }
  }
}

void handleNewPos(int &cr, int i){
  if(!fin[cr]) return;
  pos[cr].PB(i);

  if(pos[cr].size() == needs[cr].k){
    int auxMin = pos[cr][pos[cr].size() - 1] + needs[cr].s.size() - pos[cr][0];
    mini[cr] = min(mini[cr], auxMin);
    pos[cr].P_F();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  FOR(i, 0, MAX){
    fin[i] = fail[i] = sure_fail[i] = 0;
    FOR(j, 0, 26) trie[i][j] = 0;
  }

  string s, t; cin >> s;
  int n, k, id; cin >> n;
  ids.resize(n, {});

  FOR(i, 0, n){
    cin >> k >> t;
    id = add(t);
    ids[i] = dt(k, id, t);
  }

  build();
  pos.resize(nds, {});
  mini.resize(nds, INF);
  needs.resize(nds, {});

  FOR(i, 0, n) needs[ids[i].id] = ids[i];

  int x, cr = 0, ccr;
  FOR(i, 0, s.size()){
    x = s[i] - 'a';

    ccr = cr = trie[cr][x];
    handleNewPos(ccr, i);
    while(sure_fail[ccr]){
      ccr = sure_fail[ccr];
      handleNewPos(ccr, i);
    }
  }

  FOR(i, 0, n){
    int auxMin = mini[ids[i].id];
    cout << (auxMin == INF ? -1 : auxMin) << "\n";
  }
 
  return 0;
}