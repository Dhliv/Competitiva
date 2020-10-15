#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

struct pol{
  int boost, loc;
  void operator() (int a, int b){
    boost = a;
    loc = b;
  }
  bool operator< (const pol &a) const { // Es necesario incluir los const
    return boost < a.boost;
  }
};

struct score{
  ll peso = LLONG_MAX, acum = 0;
  void operator() (ll a, int b){
    peso = a;
    acum = b;
  }
};

int main(){
  int n, m, k, ori, dest, x, y, l;
  pol a, b;
  cin >> n >> m;
  vector<vector<pair<int, int> > > grafo(n);
  vector<bool> bos(n);
  
  FOR(i, 0, m){
    cin >> x >> y >> k;
    grafo[x].PB(MP(y, k));
    grafo[y].PB(MP(x, k));
  }
  
  cin >> m;
  priority_queue<pair<ll, pol> > p;
  vector<score> sp(n);
  vector<bool> vsp(n), vistos(n);
  
  FOR(i, 0, m){ // Policias.
    cin >> x;
    a(0, x);
    p.push(MP(0, a));
    sp[x](0, 0);
  }
  
  cin >> m;
  
  FOR(i, 0, m){ // Boosters
    cin >> x;
    bos[x] = 1;
  }
  
  cin >> ori >> dest;
  
  vector<ll> seen(n, LLONG_MAX);
  priority_queue<pair<ll, int> > t;
  seen[ori] = 0;
  t.push(MP(0, ori));
  
  while(!t.empty()){
    x = t.top().s;
    t.pop();
    
    if(vistos[x]) continue;
    vistos[x] = 1;
    
    FOR(i, 0, grafo[x].size()){
      y = grafo[x][i].f;
      k = grafo[x][i].s;
      
      if(seen[y] > seen[x] + k){
        seen[y] = seen[x] + k;
        t.push(MP(-seen[y], y));
      }
    }
  }
  
  while(!p.empty()){
    a = p.top().s;
    x = a.loc;
    p.pop();
    
    if(vsp[x]) continue;
    vsp[x] = 1;
    
    if(bos[x]) a.boost = 1;
    
    FOR(i, 0, grafo[x].size()){
      y = grafo[x][i].f;
      k = grafo[x][i].s;
      if(a.boost){
        l = k%2;
        k /= 2;
        if(sp[x].acum) l += 1;
        if(l/2){
          k++;
          l = 0;
        }
      }
      
      if(sp[y].peso > sp[x].peso + k){
        sp[y](sp[x].peso + k, l);
        a(a.boost, y);
        p.push(MP(-sp[y].peso, a));
      }
      else if(sp[y].peso == sp[x].peso + k and sp[y].acum > l){
        sp[y](sp[x].peso + k, 0);
        a(a.boost, y);
        p.push(MP(-sp[y].peso, a));
      }
    }
  }
  
  if(seen[dest] > sp[dest].peso) cout << "-1\n";
  else if(seen[dest] == sp[dest].peso and sp[dest].acum == 0) cout << "-1\n";
  else cout << seen[dest] << "\n";
  
  return 0;
}