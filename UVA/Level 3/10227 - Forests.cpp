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

int grupos;

vector<int> parse(string &s){
	s.PB(' ');
	vector<int> p;
	string a = "";

	FOR(i, 0, s.size()){
		if(isspace(s[i])){
			p.PB(stoi(a) - 1);
			a = "";
		}else a.PB(s[i]);
	}

	return p;
}

int find(int x, vector<int> &p){
	if(x == p[x]) return x;
	return p[x] = find(p[x], p);
}

void merge(int a, int b, vector<int> &p, vector<int> &s){
	a = find(a, p);
	b = find(b, p);
	if(s[b] > s[a]) swap(a, b);

	if(a != b){
		p[b] = a;
		s[a] += s[b];
		grupos--;
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m; cin >> t;
	string a;

	FOR(ab, 0, t){
		if(ab) cout << "\n";

		cin >> m >> n;
		vector<int> d, p(m), s(m, 1);
		FOR(i, 0, m) p[i] = i;

		vector<bitset<100> > datos(m);
		getline(cin, a);
		vector<int> ax;

		while(getline(cin, a)){
			if(a.size() == 0) break;

			ax = parse(a);
			datos[ax[0]][ax[1]] = 1;
		}

		grupos = m;
		FOR(i, 0, m - 1){
			FOR(j, i + 1, m){
				if(datos[i] == datos[j]) merge(i, j, p, s);
			}
		}

		cout << grupos << "\n";
	}
 
	return 0;
}