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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x, v; cin >> n >> x;
  map<int, int> p;
  map<int, vector<int> > posi;
  vector<int> vacio;

  FOR(i, 0, n){
    cin >> v;
    auto it = p.find(v);

    if(it != p.end()) it->s++;
    else{
      p.insert(MP(v, 1));
      posi.insert(MP(v, vacio));
    }

      posi[v].PB(i + 1);

  }

  for(const auto &y: p){
    if(y.f >= x) break;

    auto it = p.find(x - y.f);
    if(it != p.end()){
      if(it->f == y.f and it->s > 1){
        auto pos = posi.find(it->f);
        cout << pos->s[0] << " " << pos->s[1] << "\n";
        return 0;
      }else if(it->f != y.f){
        cout << posi[it->f][0] << " " << posi[y.f][0] << "\n";
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
