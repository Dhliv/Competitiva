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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, aux; cin >> s;

	aux = "";
	FOR(i, 0, s.size()) aux.PB(s[i]);
	aux.PB('$');
	FOR(i, 0, s.size()) aux.PB(s[i]);

	vector<int> z = z_function(aux);

	int ini = s.size() + 1, ans = 0, l = -1, next, maxi, mini;
	FORI(i, aux.size() - 1, ini + 1){
		if(i + z[i] == aux.size()){
			l = i;
			maxi = z[i];
			mini = z[i];
			break;
		}
	}

	FORI(i, l - 1, ini + 1){
		if(z[i] != 0 and z[i] >= mini){
			ans = max(ans, min(maxi, z[i]));

			if(z[i] + i == aux.size()) maxi = z[i];
		}
	}

	if(ans == 0) cout << "Just a legend\n";
	else{
		FOR(i, 0, ans) cout << s[i];
		cout << "\n";
	}
 
	return 0;
}