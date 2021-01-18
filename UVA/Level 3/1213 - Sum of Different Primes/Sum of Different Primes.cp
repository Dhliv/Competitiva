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

int c, k, n;
int dp[187][1121][15];
vector<int> prims;

int f(int i, int lef, int t){
  if(t == k and lef == 0) return 1;
  if(t == k) return 0;
  if(i == n) return 0;
  int &ans = dp[i][lef][t];
  if(ans != -1) return ans;
  
  
  ans = f(i + 1, lef, t);
  if(lef >= prims[i]) ans += f(i + 1, lef - prims[i], t + 1);
  
  return ans;
}

int main(){
  int l = 2000;
  vector<bool> p(l);
  
  FOR(i, 2, l){
    if(!p[i]){
      prims.PB(i);
      for(int j = 2*i; j < l; j += i) p[j] = true;
    }
  }
  
  while(cin >> c >> k, c + k){
    n = lower_bound(prims.begin(), prims.end(), c) - prims.begin();
    if(prims[n] == c) n++;
    
    memset(dp, -1, sizeof(dp));
    cout << f(0, c, 0) << "\n";
  }
  
  return 0;
}