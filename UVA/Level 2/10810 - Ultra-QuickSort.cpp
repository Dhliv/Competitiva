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

ll ans;

void ms(int l, int r, vector<int> &p, vector<int> &p2){
	if(r == l) return;

	int m = (l + r)/2;
	ms(l, m, p, p2);
	ms(m + 1, r, p, p2);

	int pl = l, pr = m + 1, pc = l;

	while(pl <= m and pr <= r){
		if(p[pl] > p[pr]){
			ans += (m - pl + 1);
			p2[pc++] = p[pr++];
		}else{
			p2[pc++] = p[pl++];
		}
	}

	while(pl <= m) p2[pc++] = p[pl++];
	while(pr <= r) p2[pc++] = p[pr++];

	FOR(i, l, r + 1) p[i] = p2[i];
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;

	while(cin >> n, n){
		vector<int> p(n), aux(n); FOR(i, 0, n) cin >> p[i];
		ans = 0;
		ms(0, n - 1, p, aux);

		cout << ans << "\n";
	}

	return 0;
}