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

int find(int x, vector<ll> &p, vector<ll> &sum){
	if(x == p[x]) return x;
	int y = find(p[x], p, sum);
	if(y != p[x]) sum[x] += sum[p[x]];
	p[x] = y;
	return y;
}

void merge(int a, int b, vector<ll> &p, vector<ll> &sum){
	p[a] = b;
	sum[a] = abs(a - b)%1000;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c, a, b, n; cin >> c;
	char k;

	FOR(ab, 0, c){
		cin >> n;

		vector<ll> p(n + 1), sum(n + 1, 0);
		FOR(i, 1, n + 1) p[i] = i;

		while(cin >> k, k != 'O'){
			cin >> a;
			if(k == 'E'){
				b = find(a, p, sum);
				cout << sum[a] << "\n";
			}else{
				cin >> b;
				merge(a, b, p, sum);
			}
		}
	}
 
	return 0;
}