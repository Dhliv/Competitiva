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

	int t, n, m; cin >> t;
	map<char, int> id;
	id.insert(MP('A', 0));
	id.insert(MP('C', 1));
	id.insert(MP('G', 2));
	id.insert(MP('T', 3));

	FOR(ab, 0, t){
		if(ab) cout << "\n";

		cin >> n >> m;
		vector<string> p(m);
		vector<pair<int, int> > ord;

		FOR(i, 0, m){
			cin >> p[i];
			vector<int> hash(4);
			hash[id.find(p[i][n - 1])->s]++;
			int sum = 0;

			FORI(j, n - 2, 0){
				int x = id.find(p[i][j])->s;
				hash[x]++;
				FOR(k, 0, x) sum += hash[k];
			}

			ord.PB(MP(sum, i));
		}

		sort(ord.begin(), ord.end());

		FOR(i, 0, m){
			cout << p[ord[i].s] << "\n";
		}
	}

	return 0;
}