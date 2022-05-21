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

	int mini, ans, n;
	string s;

	while(cin >> n, n){
		ans = 0;
		mini = INF;
		vector<int> p(n);
		getline(cin, s);

		FOR(i, 0, n){
			getline(cin, s);
			int c = 0;
			FOR(j, 0, s.size()) if(isspace(s[j])) c++;

			mini = min(mini, c);
			p[i] = c;
		}

		FOR(i, 0, n){
			ans += (p[i] - mini);
		}

		cout << ans << "\n";
	}
 
	return 0;
}