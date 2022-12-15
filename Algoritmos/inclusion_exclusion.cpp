ll inclusionExclusion(int pos, int size, ll res, ll x, vector<ll> &p){
  if(res > x) return 0;
  if(size == 0) return x/res;

  ll ans = 0;
  FOR(i, pos, p.size()){
    ans += inclusionExclusion(i + 1, size - 1, res*p[i]/__gcd(res, p[i]), x, p);
  }

  return ans;
}