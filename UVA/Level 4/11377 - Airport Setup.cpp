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
	int x, y, a, b, ori, dest, qr, id;
	int n, m, k;

	FOR(ab, 0, t){
		cout << "Case " << ab + 1 << ":\n";
		cin >> n >> m >> k;
		vector<int> s(n + 1, INF), air(n + 1), ariOri;
		vector<vector<int> > g(n + 1);

		FOR(i, 0, k){
			cin >> x;
			air[x] = 1;
		}

		ariOri = air;

		FOR(i, 0, m){
			cin >> x >> y;
			g[x].PB(y);
			g[y].PB(x);
		}

		cin >> qr;
		deque<int> q, next;
		FOR(i, 0, qr){
			cin >> ori >> dest;

			if(ori == dest){
				cout << "0\n";
				continue;
			}

			FOR(j, 1, n + 1) s[j] = INF;

			q.PB(ori);
			s[ori] = 0;
			id = 0;
			if(air[ori] == 0){
				s[ori] = 1;
				id = 1;
				air[ori] = 1;
			}

			while(!q.empty()){

				while(!q.empty()){
					x = q.F(); q.P_F();

					for(auto &y: g[x]){
						if(s[y] != INF) continue;

						if(air[y]){
							s[y] = id;
							q.PB(y);
						}else{
							s[y] = id + 1;
							next.PB(y);
						}
					}
				}

				id++;

				while(!next.empty()){
					x = next.F(); next.P_F(); 

					q.PB(x);
					air[x] = 1;
				}
			}

			air = ariOri;
			cout << (s[dest] == INF ? -1 : s[dest]) << "\n";
		}

		cout << "\n";
	} 
	
	return 0;
}