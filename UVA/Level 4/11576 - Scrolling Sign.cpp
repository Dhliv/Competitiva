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

int kmp(string &s){
	int j = 0;
	vector<int> z(s.size());

	FOR(i, 1, s.size()){
		j = z[i - 1];

		while(j > 0 and s[i] != s[j]) j = z[j - 1];
		if(s[i] == s[j]) j++;
		z[i] = j;
	}

	return z[s.size() - 1];
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	int n, m, last, ans, z;
	string a, b, ab;

	while(t--){
		cin >> m >> n;

		cin >> a;
		ans = 0;
		FOR(i, 1, n){
			cin >> b;
			ab = b + "#" + a;
			ans += kmp(ab);
			a = b;
		}

		cout << (m*n - ans) << "\n";
	}
  
	return 0;
}