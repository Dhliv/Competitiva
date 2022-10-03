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

	int t, n, ans; cin >> t;
	string s;

	FOR(ab, 0, t){
		cin >> n >> s;
		s = '#' + s + "*";
		int l = (n - 1)/2 + 1, r = n/2 + 1;

		FOR(i, r + 1, n + 2){
			if(s[i] != s[r]){
				r = i - 1;
				break;                                                                                                                                   
			}
		}

		FORI(i, l - 1, 0){
			if(s[i] != s[l]){
				l = i + 1;
				break;
			}
		}

		cout << (r - l + 1) << "\n";
	}
 
	return 0;
}