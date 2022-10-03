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
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	while(cin >> n >> m, n + m){
		vector<int> p(n), q(m);
		int l, r;
		l = r = 0;

		FOR(i, 0, n) cin >> p[i];
		FOR(i, 0, m) cin >> q[i];

		sort(p.begin(), p.end());
		sort(q.begin(), q.end());

		ll ans = 0;

		while(l < p.size() and r < q.size()){
			if(q[r] >= p[l]){
				ans += q[r];
				l++;
			}

			r++;
		}

		if(l == p.size()) cout << ans << "\n";
		else cout << "Loowater is doomed!\n";
	}
 
	return 0;
}