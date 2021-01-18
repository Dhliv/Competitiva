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

using namespace std;

int dp[20][201][201], n;

bool f(int i, int m1, int m2, deque<int> &q){
  if(i == n and m1 == m2) return true;
  if(i == n) return false;
  int &ans = dp[i][m1][m2];
  if(ans != -1) return ans;
  
  return ans = (f(i + 1, m1 + q[i], m2, q) or f(i + 1, m1, m2 + q[i], q));
}

int main(){
  int cases;
  string ent, d;
  bool ans;
  cin >> cases;
  getline(cin, ent);
  
  FOR(a, 0, cases){
    getline(cin, ent);
    deque<int> q;
    ent += " ";
    
    FOR(i, 0, ent.size()){
      if(isspace(ent[i])){
        q.PB(stoi(d));
        d = "";
      }else d += ent[i];
    }
    
    n = q.size();
    memset(dp, -1, sizeof(dp));
    ans = f(0, 0, 0, q);
    if(ans) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}