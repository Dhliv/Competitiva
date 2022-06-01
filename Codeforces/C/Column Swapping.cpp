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
 
	int t, n, m, vcs, x, y; cin >> t;
	bool able;
 
	FOR(ab, 0, t){
		cin >> n >> m;
		vector<vector<int> > p(n, vector<int> (m)), cp;
		FOR(i, 0, n){
			FOR(j, 0, m) cin >> p[i][j];
		}
 
		cp = p;
		FOR(i, 0, n) sort(cp[i].begin(), cp[i].end());
		set<pair<int, int> > pos;
 
		able = true;
		FOR(i, 0, n){
			vcs = 0;
			FOR(j, 0, m){
				if(p[i][j] != cp[i][j]){
					vcs++;
					if(vcs == 1) x = j;
					else if(vcs == 2){
						y = j;
						pos.insert(MP(x, y));
 
						if(pos.size() > 1){
							able = false;
							break;
						}
					}else{
						able = false;
						break;
					}
				}
			}
 
			if(!able) break;
		}
 
		if(!able) cout << "-1\n";
		else{
 
			if(pos.size() == 0) cout << "1 1\n";
			else{
				x = (*pos.begin()).f;
				y = (*pos.begin()).s;
 
				FOR(i, 0, n){
					if(p[i][x] < p[i][y]){
						able = false;
						break;
					}
				}
 
				if(able) cout << x + 1 << " " << y + 1 << "\n";
				else cout << "-1\n";
			}
		}
	}
 
	return 0;
}