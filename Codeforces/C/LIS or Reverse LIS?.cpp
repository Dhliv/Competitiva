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

	int t, n, x, y, dif, ans, a, b, l, r; cin >> t;

	FOR(ab, 0, t){
		cin >> n;
		map<int, int> p;
		FOR(i, 0, n){
			cin >> x;
			auto it = p.find(x);
			if(it != p.end()) it->s++;
			else p.insert(MP(x, 1));
		}

		ans = 0; dif = 0;
		for(const auto &a: p){
			if(a.s != 1){
				ans++;
			}
			else{
				dif++;
			}
		}

		cout << ans + dif/2 + dif%2 << "\n";
	}
 
	return 0;
}