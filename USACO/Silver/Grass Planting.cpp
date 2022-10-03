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

	ifstream cin("planting.in");
	ofstream cout("planting.out");

	int n, x, y, ans = 1;
	cin >> n;

	vector<vector<int> > g(n);

	FOR(i, 0, n - 1){
		cin >> x >> y;
		x--; y--;
		g[x].PB(y);
		g[y].PB(x);
	}

	FOR(i, 0, n){
		ans = max(ans, ((int) g[i].size()) + 1);
	}

	cout << ans << "\n";
 
	return 0;
}