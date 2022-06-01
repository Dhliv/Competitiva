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

int id, n;

int find(int x, vector<int> &p){
	if(x == p[x]) return x;
	return p[x] = find(p[x], p);
}

void merge(int a, int b, vector<int> &p, vector<int> &s, vector<ll> &sum, map<int, int> &ids){
	int x, y;

	auto it = ids.find(a);
	if(it != ids.end()) x = it->s;
	else x = a;

	it = ids.find(b);
	if(it != ids.end()) y = it->s;
	else y = b;

	x = find(x, p);
	y = find(y, p);
	if(s[y] > s[x]) swap(x, y);

	if(x != y){
		p[y] = x;
		s[x] += s[y];
		sum[x] += sum[y];
	}
}

void erase(int a, int b, vector<int> &p, vector<int> &s, vector<ll> &sum, map<int, int> &ids){
	int x, y, lastNode, ax;

	auto it = ids.find(a);
	if(it != ids.end()) lastNode = it->s;
	else lastNode = a;

	it = ids.find(b);
	if(it != ids.end()) y = it->s;
	else y = b;

	if(find(lastNode, p) == find(y, p)) return;
	x = id + n;
	ids[a] = x;
	s[x] = 1;
	sum[x] = a;

	ax = find(lastNode, p);
	sum[ax] -= a;
	s[ax]--;

	merge(x, y, p, s, sum, ids);
	
	id++;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, t, a, b, nodes;

	while(cin >> n >> m){
		id = 1;
		nodes = n + 2 + m;
		vector<int> s(nodes, 1), p(nodes);
		vector<ll> sum(nodes);
		FOR(i, 0, nodes) p[i] = i;
		FOR(i, 1, n + 1) sum[i] = i;
		map<int, int> ids;

		FOR(i, 0, m){
			cin >> t >> a;

			if(t == 1){
				cin >> b;
				merge(a, b, p, s, sum, ids);
			}else if(t == 2){
				cin >> b;
				erase(a, b, p, s, sum, ids);
			}else{
				auto it = ids.find(a);
				if(it != ids.end()) a = it->s;
				a = find(a, p);
				cout << s[a] << " " << sum[a] << "\n";
			}
		}
	}
 
	return 0;
}