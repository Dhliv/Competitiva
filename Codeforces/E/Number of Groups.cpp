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

struct seg{
	int c, x, id, fin;

	void operator() (int c, int x, int id, int fin){
		this->x = x;
		this->c = c;
		this->id = id;
		this->fin = fin;
	}
};

bool comp(seg &a, seg &b){
	if(a.x < b.x) return true;
	if(a.x == b.x){
		return a.fin < b.fin;
	}

	return false;
}

int find(int x, vector<int> &p){
	if(x == p[x]) return x;
	return p[x] = find(p[x], p);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, c, l, r, g, x, y; cin >> t;

	FOR(ab, 0, t){
		cin >> n;
		g = n;
		vector<seg> p(2*n);
		vector<pair<int, int> > ori(n);

		FOR(i, 0, n){
			cin >> c >> l >> r;
			ori[i] = MP(l, r);
			p[2*i](c, l, i, 0);
			p[2*i + 1](c, r, i, 1);
		}

		sort(p.begin(), p.end(), comp);

		vector<int> pa(n); FOR(i, 0, n) pa[i] = i;
		set<int> azul, rojo;
		int idr, ida, maxr = -1, maxa = -1;

		FOR(i, 0, 2*n){
			if(p[i].fin){
				if(p[i].c == 0){
					auto it = rojo.find(p[i].id);
					if(it != rojo.end()) rojo.erase(p[i].id);
				}else{
					auto it = azul.find(p[i].id);
					if(it != azul.end()) azul.erase(p[i].id);
				}
			}else{
				x = find(p[i].id, pa);

				if(p[i].c == 0){
					for(const auto &y: azul){
						int ay = find(y, pa);
						if(x != ay){
							pa[ay] = x;
							g--;
						}
					}

					if(azul.size() > 1){
						azul.clear();
						azul.insert(ida);
					}

					if(maxr < ori[p[i].id].s){
						maxr = ori[p[i].id].s;
						idr = p[i].id;
					}

					rojo.insert(p[i].id);
				}else{
					for(const auto &y: rojo){
						int ay = find(y, pa);
						if(x != ay){
							pa[ay] = x;
							g--;
						}
					}

					if(rojo.size() > 1){
						rojo.clear();
						rojo.insert(idr);
					}

					if(maxa < ori[p[i].id].s){
						maxa = ori[p[i].id].s;
						ida = p[i].id;
					}

					azul.insert(p[i].id);
				}
			}
		}

		cout << g << "\n";
	}
 
	return 0;
}