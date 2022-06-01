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

	cout.precision(1);
	int n, m, x, y, w, id = 1, k1, k2;
	double tmax, ax;
	bool dos;

	while(cin >> n >> m, n + m){
		cout << "System #" << id++ << "\n";
		vector<vector<pair<int, int> > > g(n + 1);
		FOR(i, 0, m){
			cin >> x >> y >> w;
			g[x].PB(MP(y, w));
			g[y].PB(MP(x, w));
		}

		priority_queue<pair<int, int> > pq;
		pq.push(MP(0, 1));
		vector<int> s(n + 1, INF), v(n + 1);
		s[1] = 0;
		tmax = 0.0;

		k1 = 1;
		dos = false;
		while(!pq.empty()){
			x = pq.top().s;
			pq.pop();

			if(s[x]*1.0 > tmax){
				tmax = s[x]*1.0;
				k1 = x;
				dos = false;
			}

			if(v[x]) continue;
			v[x] = 1;

			for(const auto &p: g[x]){
				y = p.f;
				w = p.s + s[x];
				if(v[y]){
					ax = (p.s*1.0 - (s[x]*1.0 - s[y]*1.0))/2.0 + s[x]*1.0
					if(ax > tmax){
						tmax = ax;
						k1 = x;
						k2 = y;
						dos = true;
					}
					continue;
				}

				if(w < s[y]){
					s[y] = w;
					pq.push(MP(-w, y));
				}
			}
		}

		cout << "The last domino falls after ";
		cout << fixed << (tmax + 0.000001) << " seconds, ";

		if(dos) cout << "between key dominoes " << min(k1, k2) << " and " << max(k2, k1) << ".\n";
		else cout << "at key domino " << k1 << ".\n";
		cout << "\n";
	}

	return 0;
}