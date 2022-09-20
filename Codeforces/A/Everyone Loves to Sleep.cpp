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

struct state{
	int h, m, id;

	void operator() (int h, int m, int id){
		this->h = h;
		this->m = m;
		this->id = id; // 0 if is bed time.
	}
};

bool comp(state &a, state &b){
	if(a.h < b.h) return true;
	if(a.h == b.h){
		if(a.m < b.m) return true;
		if(a.m == b.m){
			return a.id < b.id;
		}
	}

	return false;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t, h, m, a, b; cin >> t;

	FOR(ab, 0, t){
		cin >> n >> h >> m;
		vector<state> p(n + 1);
		p[n](h, m, 0);

		FOR(i, 0, n){
			cin >> a >> b;
			p[i](a, b, 1);
		}

		sort(p.begin(), p.end(), comp);

		int pos = 0;
		FOR(i, 0, n + 1){
			if(p[i].id == 0) pos = i;
		}

		pos = (pos + 1)%(n + 1);
		int ans = 0;

		while(h != p[pos].h or m != p[pos].m){
			m++;
			ans++;
			h += m/60;
			m %= 60;
			h %= 24;
		}

		cout << ans/60 << " " << ans%60 << "\n";
	}
 
	return 0;
}