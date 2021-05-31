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