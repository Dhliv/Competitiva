#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
#define MAX 1000005

using namespace std;

int nds = 1;
int trie[MAX][26], sum[MAX];
bool fin[MAX];
vector<vector<int> > fins(MAX), all(MAX);

void add(string &s, int pos){
  int cr = 0, x;
  
  for(char c: s){
    x = c - 'a';
    if(trie[cr][x] == 0) trie[cr][x] = nds++;
    cr = trie[cr][x];
    sum[cr]++;
    all[cr].PB(pos);
  }
  
  fin[cr] = 1;
  fins[cr].PB(pos);
}

void ers(string &s, int &pos){
  int cr = 0, x;
  
  for(char c: s){
    x = c - 'a';
    cr = trie[cr][x];
    sum[cr]--;
    FOR(i, 0, all[cr].size()){
      if(pos == all[cr][i]){
        all[cr].erase(all[cr].begin() + i);
        break;
      }
    }
  }
  
  FOR(i, 0, fins[cr].size()){
    if(pos == fins[cr][i]){
      fins[cr].erase(fins[cr].begin() + i);
      break;
    }
  }
  
  if(fins[cr].size() == 0) fin[cr] = 0;
}

bool qr(string &s, int &t, int &i, int &j){
  int cr = 0, x, y;
  
  if(t == 2){ //buscar prefijo de S.
    for(char c: s){
      x = c - 'a';
      if(trie[cr][x] == 0) return false;
      cr = trie[cr][x];
      if(sum[cr] == 0) return false;
      if(fin[cr]){
        FOR(k, 0, fins[cr].size()){
          y = fins[cr][k];
          if(i <= y and y <= j) return true;
        }
      }
    }
  }else{ // buscar si S es prefijo.
    for(char c: s){
      x = c - 'a';
      if(trie[cr][x] == 0) return false;
      cr = trie[cr][x];
      if(sum[cr] == 0) return false;
    }
    
    FOR(k, 0, all[cr].size()){
      y = all[cr][k];
      if(i <= y and y <= j) return true;
    }
  }
  
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, q, t, x, y;
  cin >> n;
  string s;
  
  memset(trie, 0, sizeof(trie));
  memset(sum, 0, sizeof(sum));
  memset(fin, 0, sizeof(fin));
  
  vector<string> p(n);
  FOR(i, 0, n){
    cin >> s;
    add(s, i);
    p[i] = s;
  }
  
  cin >> q;
  FOR(i, 0, q){
    cin >> t;
    if(t == 1){
      cin >> x >> s;
      x--;
      ers(p[x], x);
      p[x] = s;
      add(s, x);
    }else{
      cin >> x >> y >> s;
      x--;
      y--;
      cout << (qr(s, t, x, y) ? "Y" : "N") << "\n";
    }
  }
  
  return 0;
}