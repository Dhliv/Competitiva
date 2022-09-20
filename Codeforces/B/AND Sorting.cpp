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

	int t, n, a, b, x; cin >> t;

	FOR(ab, 0, t){
		cin >> n;
		vector<int> p(n), ps; FOR(i, 0, n) cin >> p[i];
		ps = p;
		sort(ps.begin(), ps.end());

		x = -1;
		FOR(i, 0, n){
			if(p[i] != ps[i]){
				if(x == -1) x = p[i];
				else x &= p[i];
			}
		}

		cout << x << "\n";
	}
 
	return 0;
}