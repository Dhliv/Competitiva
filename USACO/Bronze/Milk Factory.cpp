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

	ifstream cin("factory.in");
	ofstream cout("factory.out");

	int n; cin >> n;
	vector<vector<int> > g(n);
	vector<int> v(n, -1), s(n);
	int id = -1, x, y;

	FOR(i, 0, n - 1){
		cin >> x >> y;
		x--; y--;
		g[x].PB(y);
	}

	FOR(i, 0, n){
		deque<int> q(1, i);
		v[i] = ++id;
		s[i]++;

		while(!q.empty()){
			x = q.F(); q.P_F();

			for(auto &y: g[x]){
				if(v[y] == id) continue;
				s[y]++;
				v[y] = id;
				q.PB(y);
			}
		}
	}

	int ans = -1;
	FOR(i, 0, n) {
		if(s[i] == n){
			ans = i + 1;
			break;
		}
	}

	cout << ans << "\n";
 
	return 0;
}