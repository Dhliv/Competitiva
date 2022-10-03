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

struct point{
	int x, y;

	void operator() (int x, int y){
		this->x = x;
		this->y = y;
	}

	void print(){
		cout << "(" << x << ", " << y << ")";
	}
};

bool operator>(point &a, point &b){
	if(a.x == b.x){
		return a.y > b.y;
	}
	return a.x > b.x;
}

void makeDivision(point &a, point &b, vector<vector<vector<vector<int> > > > &g){
	if(a > b) swap(a, b);

	if(a.x == b.x){
		// horizontal line.
		if(a.x == 0 or a.x == 6) return;

		FOR(i, a.y, b.y){
			//cout << "(" << a.x << ", " << i + 1 << ") <-> (" << a.x + 1 << ", " << i + 1 << ")\n";
			g[a.x][i + 1][a.x + 1][i + 1] = -1;
			g[a.x + 1][i + 1][a.x][i + 1] = -1;
		}
	}else{
		// vertical line.
		if(a.y == 0 or a.y == 6) return;

		FOR(i, a.x, b.x){
			//cout << "(" << i + 1 << ", " << a.y << ") <-> (" << i + 1 << ", " << a.y + 1 << ")\n";
			g[i + 1][a.y][i + 1][a.y + 1] = -1;
			g[i + 1][a.y + 1][i + 1][a.y] = -1;
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	point ini, dest, a, b;
	int MAX = 7;

	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	char dir[4] = {'N', 'E', 'S', 'W'};
	int x, y;

	while(cin >> ini.y >> ini.x, ini.x + ini.y){
		cin >> dest.y >> dest.x;

		vector<vector<vector<vector<int> > > > g(MAX, vector<vector<vector<int> > > (MAX, vector<vector<int> > (MAX, vector<int> (MAX))));

		FOR(i, 0, 3){
			cin >> a.y >> a.x >> b.y >> b.x;
			makeDivision(a, b, g);
		}

		deque<point> q;
		q.PB(ini);
		vector<vector<char> > s(MAX, vector<char> (MAX, 'A'));
		vector<vector<point> > f(MAX, vector<point> (MAX));
		s[ini.x][ini.y] = 'O';

		while(!q.empty()){
			a = q.F(); q.P_F();

			FOR(i, 0, 4){
				x = a.x + dx[i];
				y = a.y + dy[i];

				if(x >= 1 and x < MAX and y >= 1 and y < MAX){
					if(g[a.x][a.y][x][y] == -1) continue;
					if(s[x][y] != 'A') continue;

					s[x][y] = dir[i];
					f[x][y] = a;
					b(x, y);
					q.PB(b);
				}
			}
		}

		string ans = "";
		while(s[dest.x][dest.y] != 'O'){
			ans.PB(s[dest.x][dest.y]);
			dest = f[dest.x][dest.y];
		}

		FORI(i, ans.size() - 1, 0) cout << ans[i];
		cout << "\n";
	}
  
	return 0;
}