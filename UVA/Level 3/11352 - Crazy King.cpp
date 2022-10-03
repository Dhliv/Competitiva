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

	int t; cin >> t;
	int x, y, n, m;
	pair<int, int> ori, dest, a;
	int kdy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int kdx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	string s;

	FOR(ab, 0, t){
		cin >> n >> m;
		vector<vector<int> > g(n, vector<int> (m)); // 0 is advance. 1 is A. 2 is B. -1 block.

		FOR(i, 0, n){
			cin >> s;

			FOR(j, 0, m){
				switch(s[j]){
					case 'Z':
							g[i][j] = -1;
							FOR(k, 0, 8){
								x = i + kdx[k];
								y = j + kdy[k];

								if(x >= 0 and x < n and y >= 0 and y < m) g[x][y] = -1;
							}
						break;
					case 'A':
						ori = MP(i, j);
						break;

					case 'B':
						dest = MP(i, j);
						break;

					default:
						break;
				}
			}
		}

		g[ori.f][ori.s] = 1;
		g[dest.f][dest.s] = 2;

		deque<pair<int, int> > q;
		vector<vector<int> > s(n, vector<int> (m, INF));
		s[ori.f][ori.s] = 0;
		q.PB(ori);

		while(!q.empty()){
			a = q.F(); q.P_F();

			FOR(i, 0, 8){
				x = a.f + dx[i];
				y = a.s + dy[i];

				if(x >= 0 and x < n and y >= 0 and y < m){
					if(s[x][y] != INF) continue;
					if(g[x][y] == -1) continue;
					s[x][y] = s[a.f][a.s] + 1;
					q.PB(MP(x, y));
				}
			}
		}

		if(s[dest.f][dest.s] == INF) cout << "King Peter, you can't go now!\n";
		else cout << "Minimal possible length of a trip is " << s[dest.f][dest.s] << "\n";
	}
 
	return 0;
}