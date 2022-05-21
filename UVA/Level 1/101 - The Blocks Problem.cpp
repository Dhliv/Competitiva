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

	int n, x, y, a, b; cin >> n;

	vector<int> p(n); FOR(i, 0, n) p[i] = i;
	vector<deque<int> > ord(n); FOR(i, 0, n) ord[i].PB(i);
	string s, t;

	while(cin >> s, s != "quit"){
		cin >> x >> t >> y;

		if(p[y] == p[x]) continue;

		if(s == "move"){
			while(ord[p[x]].B() != x){
				a = ord[p[x]].B(); ord[p[x]].P_B();
				p[a] = a;
				ord[a].PB(a);
			}

			ord[p[x]].P_B();

			if(t == "onto"){
				while(ord[p[y]].B() != y){
					a = ord[p[y]].B(); ord[p[y]].P_B();
					p[a] = a;
					ord[a].PB(a);
				}
			}

			ord[p[y]].PB(x);
			p[x] = p[y];
		}else{
			if(t == "onto"){
				while(ord[p[y]].B() != y){
					a = ord[p[y]].B(); ord[p[y]].P_B();
					p[a] = a;
					ord[a].PB(a);
				}
			}

			deque<int> ax;
			while(ord[p[x]].B() != x){
				a = ord[p[x]].B(); ord[p[x]].P_B();
				ax.PB(a);
				p[a] = p[y];
			}

			ax.PB(x); ord[p[x]].P_B(); p[x] = p[y];

			while(!ax.empty()){
				ord[p[y]].PB(ax.B());
				ax.P_B();
			}
		}
	}

	FOR(i, 0, n){
		cout << i << ":";
		FOR(j, 0, ord[i].size()) cout << " " << ord[i][j];
		cout << "\n";
	}
 
	return 0;
}