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

	int t, n, u, z, fz, lz; cin >> t;
	string s;

	FOR(ab, 0, t){
		cin >> n >> s;
		deque<pair<int, int> > p;

		z = u = 0;
		fz = -1;
		FOR(i, 0, s.size()){
			if(s[i] == '0'){
				z++;
			}else u++;

			p.PB(MP(s[i] - '0', i));
		}

		if(u & 1 or z == n) cout << "NO\n";
		else{
			cout << "YES\n";

			if(u == n){
				FOR(i, 2, n + 1) cout << "1 " << i << "\n";
			}else{
				FOR(i, 0, fz){
					p.PB(p.F());
					p.P_F();
				}

				while(p.B().f == 0){
					p.PF(p.B());
					p.P_B();
				}

				vector<int> con(n);
				FOR(i, 1, n){
					if(con[i]%2 == p[i].f and con[i] != 0) continue;

					if(p[i].f == 1) cout << p[0].s + 1 << " " << p[i].s + 1 << "\n";
					else{
						if(con[i]) cout << p[i].s + 1 << " " << p[i + 1].s + 1 << "\n";
						else{
							cout << p[0].s + 1 << " " << p[i].s + 1 << "\n";
							cout << p[i].s + 1 << " " << p[i + 1].s + 1 << "\n";
						}
						con[i + 1]++;
					}
				}
			}
		}
	}
 
	return 0;
}