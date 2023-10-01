#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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
#define MAX1 160
#define MAX 1001

using namespace std;

int r, c;

bool isValid(int x){
  vector<int> impact(r);
  FOR(i, 0, r){
    if(x & 1 << i){
      FOR(j, max((ll)0, i - 1), min((ll)r - 1, i + 1) + 1) impact[j]++;
    }
  }

  FOR(i, 0, r){
    if(x & 1 << i and impact[i] > 1) return false;
  }

  return true;
}

vector<vector<int> > buildNext(vector<int> &ans){
  vector<vector<int> > av(ans.size());

  int mask, xr;
  FOR(i, 0, ans.size()){
    FOR(j, 0, ans.size()){
      xr = ans[i] ^ ans[j];
      mask = ans[i] | ans[j];
      if(xr != mask) continue;
      if(isValid(mask)) av[i].PB(j);
    }
  }

  return av;
}

vector<int> build(){
  vector<int> ans;

  FOR(i, 0, 1 << r){
    if(isValid(i)) ans.PB(i);
  }

  return ans;
}

ll dp[MAX][MAX1];
const ll MOD = 1000000007;

ll f(int i, int j, vector<vector<int> > &next){
  if(i == c) return 1;
  ll &ans = dp[i][j];
  if(ans != -1) return ans;

  ans = 0;
  FOR(k, 0, next[j].size()) ans = (ans + f(i + 1, next[j][k], next))%MOD;

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;
  vector<int> ans = build();
  vector<vector<int> > av = buildNext(ans);

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0, av) << "\n";

  return 0;
}