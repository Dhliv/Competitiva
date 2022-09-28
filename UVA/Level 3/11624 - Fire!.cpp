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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

void bfs(deque<pair<int, int> > &q, deque<pair<int, int> > &next, vector<vector<int> > &g, vector<vector<int> > &s, bool joe){
	pair<int, int> a;
	int x, y;

	while(!q.empty()){
		a = q.F(); q.P_F();

		FOR(i, 0, 4){
			if(joe and g[a.f][a.s] < 0) continue;

			x = a.f + dx[i];
			y = a.s + dy[i];

			if(x >= 0 and x < n and y >= 0 and y < m){
				if(g[x][y] < 0) continue;
				if(s[x][y] != INF) continue;
				g[x][y] = joe ? 1 : -2;
				s[x][y] = 1 + s[a.f][a.s];
				next.PB(MP(x, y));
			}
		}
	}

	q.swap(next);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	int x, y;
	pair<int, int> a, b, ori;
	string s;

	const int MAX = 1000;

	// -1 is wall.
	// 0 is pass.
	// - 2 is Fire
	vector<vector<int> > g(MAX, vector<int> (MAX)), s1(MAX, vector<int> (MAX, INF)), s2(MAX, vector<int> (MAX, INF));

	while(t--){
		cin >> n >> m;

		FOR(i, 0, n){
			FOR(j, 0, m){
				s1[i][j] = s2[i][j] = INF;
			}
		}

		deque<pair<int, int> > fire, joe, next;

		FOR(i, 0, n){
			cin >> s;
			FOR(j, 0, m){
				switch (s[j]){
					case 'J':
						joe.PB(MP(i, j));
						g[i][j] = 1;
						s1[i][j] = 0;
						break;
					case 'F':
						s2[i][j] = 0;
						g[i][j] = -2;
						fire.PB(MP(i, j));
						break;
					case '#':
						g[i][j] = -1;
						break;
					default:
						g[i][j] = 0;
						break;
				}
			}
		}

		bool turn = 0;
		while(!joe.empty()){

			if(turn){
				// Fire turn.
				bfs(fire, next, g, s2, false);
			}else{
				// Joe turn.
				bfs(joe, next, g, s1, true);
			}

			turn = 1 - turn;
		}

		int ans = INF;
		FOR(i, 0, m){
			if(s1[0][i] < s2[0][i]) ans = min(ans, s1[0][i]);
			if(s1[n - 1][i] < s2[n - 1][i]) ans = min(ans, s1[n - 1][i]);
		}

		FOR(i, 0, n){
			if(s1[i][0] < s2[i][0]) ans = min(ans, s1[i][0]);
			if(s1[i][m - 1] < s2[i][m - 1]) ans = min(ans, s1[i][m - 1]);
		}

		if(ans == INF) cout << "IMPOSSIBLE\n";
		else cout << ans + 1 << "\n";
	}
 
	return 0;
}