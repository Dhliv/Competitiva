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

struct edge{
	int y, w;
	char k;

	void operator() (int y, string s){
		this->y = y;
		k = s[0];
		w = s.size();
	}
};

void assignId(int &x, string &s, map<string, int> &id){
	if(id.count(s)) x = id[s];
	else{
		x = id.size();
		id.insert(MP(s, x));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, x, y, w, n;
	char k;
	string a, b, c, ori, dest;
	edge e;

	while(cin >> m, m){
		map<string, int> id;
		vector<vector<edge> > g(5000);
		cin >> ori >> dest;
		assignId(x, ori, id);
		assignId(x, dest, id);

		FOR(i, 0, m){
			cin >> a >> b >> c;

			assignId(x, a, id);
			assignId(y, b, id);

			e(y, c);
			g[x].PB(e);
			e(x, c);
			g[y].PB(e);
		}

		int ans = INF;

		for(const auto &something: g[id[ori]]){
			priority_queue<pair<int, pair<int, char> > > pq;
			vector<int> s(id.size(), INF), v(id.size());
			x = id[ori];
			v[x] = 1;
			y = something.y;
			s[y] = something.w;
			pq.push(MP(-s[y], MP(y, something.k)));
			s[x] = 0;

			while(!pq.empty()){
				x = pq.top().s.f;
				k = pq.top().s.s;
				pq.pop();

				if(v[x]) continue;
				v[x] = 1;

				for(const auto &e: g[x]){
					w = s[x] + e.w;
					if(v[e.y] or e.k == k) continue;

					if(w < s[e.y]){
						s[e.y] = w;
						pq.push(MP(-w, MP(e.y, e.k)));
					}
				}
			}

			ans = min(ans, s[id[dest]]);
		}

		if(ans == INF) cout << "impossivel\n";
		else cout << ans << "\n";
	}

	return 0;
}