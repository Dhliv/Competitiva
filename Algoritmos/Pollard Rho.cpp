ll mult(ll a, ll b, ll mod) {
    return ((__int128)a * b) % mod;
}

ll f(ll x, ll c, ll mod) {
    return (mult(x, x, mod) + c) % mod;
}

ll rho(ll n) {
  ll c = 1, x, y, g;
  y = x = 2;
  g = c;
  while(g == 1){
    x = f(x, c, n);
    y = f(y, c, n);
    y = f(y, c, n);
    g = __gcd(abs(x - y), n);
  }
  return g;
}