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

deque<int> prims;

void insrt(int a, vector<ll> &p){
  int n = a;
  for(int i = 0; i < prims.size() and n > 1; i++){
    while(n%prims[i] == 0){
      p[prims[i]]++;
      n /= prims[i];
    }
  }

  return;
}

ll pw(int p, ll pwr){
  ll ans = 1;

  FOR(i, 0, pwr) ans *= p;

  return ans;
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, mn;

  vector<bool> s(101);

  FOR(i, 2, 101){
    if(!s[i]){
      s[i] = 1;
      prims.PB(i);
      for(int j = 2*i; j <= 100; j += i) s[j] = 1;
    }
  }

  while(cin >> n >> m, n + m){
    vector<ll> a(101), b(101), c(101);

    mn = n - m;

    FOR(i, 2, 101){
      if(n >= i) insrt(i, a);
      if(m >= i) insrt(i, b);
      if(mn >= i) insrt(i, c);
    }

    ll ans = 1;
    FOR(i, 0, prims.size()){
      a[prims[i]] -= (b[prims[i]] + c[prims[i]]);
      ans *= (a[prims[i]] > 0 ? pw(prims[i], a[prims[i]]) : 1);
    }

    cout << n << " things taken " << m << " at a time is " << ans << " exactly.\n";
  }

  return 0;
}