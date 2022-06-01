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

bool comp(const pair<int, int> &a, const pair<int, int> &b){
	return a.f > b.f;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int g, p, s, k, x;

	while(cin >> g >> p, g + p){
		vector<vector<pair<int, int> > > races(g, vector<pair<int, int> > (p));

		FOR(ab, 0, g){
			FOR(i, 0, p){
				cin >> races[ab][i].f;
				races[ab][i].s = i;
			}
			sort(races[ab].begin(), races[ab].end());
		}

		cin >> s;
		vector<vector<int> > psystem(s);
		FOR(i, 0, s){
			cin >> k;
			vector<pair<int, int>> results(p);
			FOR(j, 0, p) results[j].s = j;

			FOR(j, 0, k){
				cin >> x;
				psystem[i].PB(x);
			}

			FOR(j, 0, g){
				FOR(l, 0, k) results[races[j][l].s].f += psystem[i][l];
			}

			sort(results.begin(), results.end(), comp);
			x = results[0].f;
			deque<int> ans;
			FOR(j, 0, p) if(results[j].f == x) ans.PB(results[j].s + 1);
			sort(ans.begin(), ans.end());

			cout << ans.F(); ans.P_F();

			while(!ans.empty()){
				cout << " " << ans.F();
				ans.P_F();
			}
			cout << "\n";
		}
	}
 
	return 0;
}