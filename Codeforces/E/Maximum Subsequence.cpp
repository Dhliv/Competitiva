#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
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
 
using namespace std;
 
const ld EPSILON = 0.000000001;

ll mod;
vector<ll> p;

void mitm(int pos, int n, deque<ll> &ans){
	int maxi = 1 << n;
	ll sum;

	FOR(i, 0, maxi){
		sum = 0;
		FOR(j, 0, n){
			if(i & (1 << j)) sum = (sum + p[j + pos])%mod;
		}

		ans.PB(sum);
	}
}

int bs(int x, deque<ll> &a){
	int l = 0, r = a.size() - 1, m;

	while(l <= r){
		m = (l + r)/2;

		if(a[m] >= x) r = m - 1;
		else l = m + 1;
	}

	return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n >> mod;
  p.assign(n, {});
  FOR(i, 0, n) cin >> p[i];

  if(n == 1){
  	cout << p[0]%mod << "\n";
  	return 0;
  }

  deque<ll> ans1, ans2;
  int hf = n/2;
  mitm(0, hf, ans1);
  mitm(hf, n - hf, ans2);
  ans1.PB(INF);
  ans2.PB(INF);

  sort(ans1.begin(), ans1.end());
  sort(ans2.begin(), ans2.end());

  deque<ll> a1, a2;
  ll bef, cnt;

  bef = ans1[0];
  FOR(i, 1, ans1.size()){
  	if(bef == ans1[i]) continue;
  	a1.PB(bef);
  	bef = ans1[i];
  }

  bef = ans2[0];
  FOR(i, 1, ans2.size()){
  	if(bef == ans2[i]) continue;
  	a2.PB(bef);
  	bef = ans2[i];
  }
  
  ll ans = 0;
  int pos, val;
  FOR(i, 0, a1.size()){
  	val = mod - 1 - a1[i];
  	pos = bs(val, a2);
  	if(pos == a2.size()) pos--;
  	if(a2[pos] > val) pos--;

  	if(pos < 0) continue;
  	ans = max(ans, a1[i] + a2[pos]);
  }

  cout << ans << "\n";

  return 0;
}