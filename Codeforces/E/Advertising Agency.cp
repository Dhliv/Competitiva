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
#define mod 1000000007

using namespace std;

ll fc[1001];

ll inv(int a){
  int n = mod - 2;
  ll dp[32], ans = 1;
  dp[0] = a;
  FOR(i, 1, 32) dp[i] = (dp[i - 1]*dp[i - 1])%mod;
  
  FOR(i, 0, 32){
    if(n & (1 << i)) ans = (ans*dp[i])%mod;
  }
  
  return ans;
}

int com(int a, int b){
  return (((fc[a]*inv(fc[b]))%mod)*inv(fc[a - b]))%mod;
}

int main(){
  ios_base::sync_with_stdio(false);
  int t, k, n, a, b;
  ll ans;
  cin >> t;
  fc[0] = 1;
  FOR(i, 1, 1001) fc[i] = (fc[i - 1]*i)%mod;
  
  FOR(ab, 0, t){
    cin >> n >> k;
    priority_queue<int> q;
    vector<int> p(n), vecs(1001);
    map<int, int> used;
    FOR(i, 0, n) {
      cin >> p[i];
      q.push(p[i]);
      vecs[p[i]]++;
    }
    
    FOR(i, 0, k){
      if(used.find(q.top()) == used.end()) used.insert(MP(q.top(), 1));
      else used[q.top()]++;
      q.pop();
    }
    
    ans = 1;
    for(auto x: used){
      ans = (ans*com(vecs[x.f], x.s))%mod;
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}