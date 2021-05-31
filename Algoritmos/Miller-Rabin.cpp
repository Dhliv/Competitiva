vector<int> a{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll mult(ll a, ll b, ll mod) {
    return ((__int128)a * b) % mod;
}

/*
  a es la base.
  d es la potencia.
  n es el modulo.
*/
ll pw(ll a, ll d, ll n){ // pow in log(n)
  vector<ll> dp(63);
  dp[0] = a;
  ll res;
  
  FOR(i, 1, 63) dp[i] = mult(dp[i - 1], dp[i - 1], n);
  
  deque<int> bits;
  
  FOR(i, 0, 63) if(d & (ll)1 << i) bits.PB(i);
  
  res = dp[bits.F()]%n;
  bits.P_F();
  
  while(!bits.empty()){
    res = (mult(res, dp[bits.F()], n))%n;
    bits.P_F();
  }
  
  return res;
}

bool prime(ll n){ // test de primalidad
  ll r, x, m, d;
  bool out;
  r = 0;
  m = n - 1;
    
  while(m%2 == 0){
    m /= 2;
    r++;
  }
  d = m;
    
  FOR(i, 0, a.size()){
    x = pw(a[i], d, n);
    out = false;
    if(x == 1 or x == n - 1) continue;
    else{
      FOR(j, 0, r - 1){
        x = mult(x, x, n);
        if(x == n - 1){
          out = true;
          break;
        }
      }
    }
      
    if(out) continue;
    return false;
  }
  return true;
}