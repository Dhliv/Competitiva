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
  int n, m, x, y;
  
  while(cin >> n >> m, n + m){
    vector<vector<int> > grafo(n + 1);
    vector<int> dirs(n + 1);
    
    FOR(i, 0, m){
      cin >> x >> y;
      grafo[x].PB(y);
      dirs[y]++;
    }
    
    deque<int> s, q;
    
    FOR(i, 1, n + 1) if(dirs[i] == 0) q.PB(i);
    
    while(!q.empty()){
      x = q.F();
      q.P_F();
      s.PB(x);
      
      FOR(i, 0, grafo[x].size()){
        y = grafo[x][i];
        dirs[y]--;
        if(dirs[y] == 0) q.PB(y);
      }
    }
    
    if(s.size() != n) cout << "IMPOSSIBLE\n";
    else{
      while(!s.empty()){
        cout << s.F() << "\n";
        s.P_F();
      }
    }
  }
  
  return 0;
}
