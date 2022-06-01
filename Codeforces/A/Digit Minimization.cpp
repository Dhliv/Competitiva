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
	string s;
	int ans;

	FOR(ab, 0, t){
		cin >> s;

		if(s.size() == 2) cout << s[1] << "\n";
		else{
			ans = 9;
			FOR(i, 0, s.size()){
				if(s[i] - '0' < ans) ans = s[i] - '0';
			}

			cout << ans << "\n";
		}
	}

	return 0;
}