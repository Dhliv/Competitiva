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

int n;
vector<int> p, s;

int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(s[b] > s[a]) swap(a, b);

	if(a != b){
		p[b] = a;
		s[a] += s[b];
	}
}

int checkRelation(int a, int b){
	int x, y;
	x = find(a);
	y = find(b);

	if(x == y) return 0; // Son amigos;
	x = find(a + n);
	if(x == y) return 1; // Son enemigos;
	return -1; // No tienen nada que ver;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, a, b, x, y; cin >> n;
	p.assign(2*n, 0);
	s.assign(2*n, 1);
	FOR(i, 0, 2*n) p[i] = i;

	while(cin >> t >> a >> b, t + a + b){
		x = checkRelation(a, b);

		if(t == 1){
			if(x == 1) cout << "-1\n";
			else{
				merge(a, b);
				merge(a + n, b + n);
			}
		}else if(t == 2){
			if(x == 0) cout << "-1\n";
			else{
				merge(a, b + n);
				merge(a + n, b);
			}
		}else if(t == 3){
			cout << (x == 0 ? 1 : 0) << "\n";
		}else{
			cout << (x == 1 ? 1 : 0) << "\n";
		}
	}
 
	return 0;
}