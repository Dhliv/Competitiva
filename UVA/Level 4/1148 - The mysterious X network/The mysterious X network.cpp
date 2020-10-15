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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int main(){
  int cases, x, y, n, h, ori, dest;
  cin >> cases;
  
  FOR(a, 0, cases){
    if(a) cout << "\n";
    
    cin >> n;
    vector<vector<int> > grafo(n);
    
    FOR(i, 0, n){
      cin >> x >> h;
      FOR(j, 0, h){
        cin >> y;
        grafo[x].PB(y);
      }
    }
    
    cin >> ori >> dest;
    
    deque<int> q;
    vector<int> seen(n, INF);
    seen[ori] = -1;
    q.PB(ori);
    
    while(!q.empty() and seen[dest] == INF){
      x = q.F();
      q.P_F();
      
      FOR(i, 0, grafo[x].size()){
        y = grafo[x][i];
        if(seen[y] == INF){
          seen[y] = 1 + seen[x];
          q.PB(y);
        }
      }
    }
    
    cout << ori << " " << dest << " " << seen[dest] << "\n";
  }
  
  return 0;
}
