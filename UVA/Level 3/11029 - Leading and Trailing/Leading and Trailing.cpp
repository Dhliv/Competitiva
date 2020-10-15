#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int o3(int n, int k){
  double x = k*log10(n);
  x -= floor(x);
  x = pow(10, x);
  x *= 100;
  
  int res = floor(x);
  
  return res;
}

int main(){
  ll cases, n, k, fi, se, mil = 1000000000;
  string res, alt;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n >> k;
    vector<ll> dp(33);
    deque<int> mul;
    dp[0] = n%mil;
    fi = o3(n, k);
    
    FOR(i, 1, 33) dp[i] = (dp[i - 1]%mil * dp[i - 1]%mil)%mil;
    
    FOR(i, 0, 33) if(k & ((long long)1 << i)) mul.PB(i);
    
    se = dp[mul.F()];
    mul.P_F();
    
    while(!mul.empty()){
      se = (se*dp[mul.F()])%mil;
      mul.P_F();
    }
    
    res = to_string(se);
    alt = "";
    cout << fi << "...";
    
    if(se == 0) cout << "000\n";
    else{
      FORI(i, res.size() - 1, res.size() - 3)
        alt += res[i];
        
      reverse(alt.begin(), alt.end());
      
      cout << alt + "\n";
    }
  }
  
  return 0;
}
