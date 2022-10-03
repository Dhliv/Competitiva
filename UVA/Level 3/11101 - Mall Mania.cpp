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

	int n, m, x, y;
	const int MAX = 2001;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	vector<vector<pair<int, int> > > s(MAX, vector<pair<int, int> > (MAX, MP(-1, INF)));
	vector<vector<int> > fin(MAX, vector<int> (MAX, -1));
	int id = -1;
	pair<int, int> a;

	while(cin >> n, n){
		id++;
		deque<pair<int, int> > q;

		FOR(i, 0, n){
			cin >> x >> y;
			s[x][y] = MP(id, 0);
			q.PB(MP(x, y));
		}

		cin >> m;
		FOR(i, 0, m){
			cin >> x >> y;
			fin[x][y] = id;
		}

		bool cont = true;
		int ans = 0;
		while(!q.empty() and cont){
			a = q.F(); q.P_F();

			FOR(i, 0, 4){
				x = a.f + dx[i];
				y = a.s + dy[i];

				if(x >= 0 and x < MAX and y >= 0 and y < MAX){
					if(s[x][y].f == id) continue;
					s[x][y] = MP(id, s[a.f][a.s].s + 1);

					if(fin[x][y] == id){
						cont = false;
						ans = s[x][y].s;
					}
					q.PB(MP(x, y));
				}
			}
		}

		cout << ans << "\n";
	}
 
	return 0;
}