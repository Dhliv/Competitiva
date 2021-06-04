#include <bits/stdc++.h>
#define INF 1000000000
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
#define LET 100
#define MAX 10010

using namespace std;

int dp[MAX][MAX];
int trie[MAX][LET], nds;
bool fin[MAX];
string s;

int l(int i, int cr){
  if(i == s.size()){
    if(fin[cr]) return 1;
    return INF;
  }
  int &ans = dp[i][cr];
  if(ans != -1) return ans;
  
  int x = s[i] - 33, ncr;
  ncr = trie[cr][x];
  
  if(ncr == 0) return INF;
  
  ans = l(i + 1, ncr);
  if(fin[ncr]) ans = min(ans, 1 + l(i + 1, 0));
  
  return ans;
}

void add(string &s){
  int cr = 0, x;
  
  for(char c: s){
    x = c - 33;
    if(trie[cr][x] == 0) trie[cr][x] = nds++;
    cr = trie[cr][x];
  }
  
  fin[cr] = true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t, n, tamT, ans;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> s >> n;
    nds = 1;
    vector<string> tad(n);
    
    tamT = 0;
    FOR(i, 0, n){
      cin >> tad[i];
      tamT += 2*tad[i].size();
    }
    
    FOR(i, 0, tamT + 1){
      FOR(j, 0, LET) trie[i][j] = 0;
      fin[i] = 0;
    }
    
    FOR(i, 0, s.size()){
      FOR(j, 0, tamT + 1) dp[i][j] = -1;
    }
    
    FOR(i, 0, n){
      add(tad[i]);
      reverse(tad[i].begin(), tad[i].end());
      add(tad[i]);
    }
    
    ans =  l(0, 0);
    
    cout << "Set " << ab + 1 << ": ";
    if(ans == INF) cout << "Not possible.\n";
    else cout << ans << ".\n";
  }
  
  return 0;
}