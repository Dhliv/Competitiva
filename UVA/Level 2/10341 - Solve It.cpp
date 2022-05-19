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

long double p, q, r, s, t, u, epsilon = 1e-6;

long double eq(long double x){
	return p*exp(-x) + q*sin(x)+ r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cout.precision(4);

	while(cin >> p >> q >> r >> s >> t >> u){
		long double l = 0.0, r = 1.0, dos = 2.0, m;
		int ite = 100;

		FOR(i, 0, ite){
			m = (l + r)/dos;
			//cout << l << " " << r << ": " << m << "; eq(m) = " << eq(m) << "\n";
			if(eq(m) >= 0.0) l = m;
			else r = m;
		}

		//cout << l << " " << r << " EOF\n";
		if(eq(0) * eq(1) > 0.0) cout << "No solution\n";
		else cout << fixed << l << "\n";
	}

	return 0;
}