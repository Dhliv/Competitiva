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

struct jiggly{
	int x, y, L;
};

bool inside(pair<int, int> a, jiggly &j){
	int x, y;
	x = a.f - j.x;
	y = a.s - j.y;
	int res = x*x + y*y;
	if(res <= j.L*j.L) return true;
	return false;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x, y, k;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	pair<int, int> a, b;

	while(cin >> n >> m, n + m){
		vector<vector<int> > s(n + 1, vector<int> (m + 1, INF));

		cin >> k;
		FOR(i, 0, k){
			cin >> x >> y;
			s[x][y]--;
		}

		cin >> k;
		vector<jiggly> jig(k);
		FOR(i, 0, k){
			cin >> jig[i].x >> jig[i].y >> jig[i].L;
		}

		deque<pair<int, int> > q;

		bool able = true;
		FOR(i, 0, k){
			if(inside(MP(1, 1), jig[i])){
				able = false;
				break;
			}
		}

		if(able){
			q.PB(MP(1, 1));
			s[1][1] = 0;
		}

		while(!q.empty()){
			a = q.F(); q.P_F();

			FOR(i, 0, 4){
				x = a.f + dx[i];
				y = a.s + dy[i];

				if(x >= 1 and x <= n and y >= 1 and y <= m){
					if(s[x][y] != INF) continue;

					able = true;
					b = MP(x, y);
					FOR(i, 0, k){
						if(inside(b, jig[i])){
							able = false;
							break;
						}
					}

					s[x][y]--;

					if(able){
						s[x][y] = 1 + s[a.f][a.s];
						q.PB(b);
					}
				}
			}
		}

		cout << (s[n][m] >= (n*m + 5) ? "Impossible." : to_string(s[n][m])) << "\n";
	}
 
	return 0;
}