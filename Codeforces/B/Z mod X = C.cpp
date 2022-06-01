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

	ll t, a, b, c, x, y, z; cin >> t;

	FOR(ab, 0, t){
		cin >> a >> b >> c;
		y = b;
		z = c;
		x = b*((c + 1)/b + ((c + 1)%b ? 1 : 0)) + a;

		cout << x << " " << y << " " << z << "\n";
	}

	return 0;
}