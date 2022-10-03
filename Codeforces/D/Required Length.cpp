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

	int n;
	ll x;
	__int128 nx;
	vector<int> seen(20, INF);
	set<__int128> dp;
	string s;

	cin >> n >> x;
	nx = x;

	dp.insert(nx);
	seen[to_string(x).size()] = 0;
	deque<pair<__int128, int> > q;
	q.PB(MP(nx, 0));

	__int128 limit;
	limit = 1;
	FOR(i, 0, n) limit *= 10;

	if(limit <= nx){
		cout << "-1\n";
		return 0;
	}

	while(!q.empty() and seen[n] == INF){
		auto x = q.F(); q.P_F();
		if(x.s > 64) continue;

		int digits = 0;
		set<int> poss;
		__int128 aux = x.f;
		while(aux != 0){
			poss.insert((int)(aux%10));
			aux /= 10;
		}

		for(const int &y: poss){
			if(y == 1 or y == 0) continue;
			aux = x.f*y;
			if(dp.find(aux) != dp.end()) continue;
			digits = 0;

			while(aux != 0){
				digits++;
				aux /= 10;
			}

			if(seen[digits] == INF) seen[digits] = x.s + 1;
			dp.insert(x.f*y);
			q.PB(MP(x.f*y, x.s + 1));
		}
	}

	if(seen[n] == INF) cout << "-1\n";
	else cout << seen[n] << "\n";
 
	return 0;
}