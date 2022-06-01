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
 
using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<ll> ans;
  ans.PB(2);

  FOR(i, 1, 1000000){
    ll daNum = 1;
    string num = to_string(i);
    if((num[0] - '0')%2 == 0) continue;
    string toConvert;
    FOR(j, 0, 2){
      toConvert = num;
      FORI(k, num.size() - 1 - j, 0) toConvert.PB(num[k]);
      daNum = stoll(toConvert);
      if(MillerRabin(daNum)){
        ans.PB(daNum);
      }
    }
  }

  sort(ans.begin(), ans.end());
  ans.PB(LLONG_MAX);

  ll a, b; cin >> a >> b;
  a--;

  int sa = lower_bound(ans.begin(), ans.end(), a) - ans.begin();
  int sb = lower_bound(ans.begin(), ans.end(), b) - ans.begin();
  if(ans[sa] == a) sa++;
  if(ans[sb] == b) sb++;

  cout << sb - sa << "\n";

  return 0;
}