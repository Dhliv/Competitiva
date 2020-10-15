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
  int g, x, y;
  double val, mini, epsi = 0.000000001;
  char k, ans;
  string ent;
  
  while(cin >> g){
    vector<vector<int> > grafo(g + 1);
    vector<string> conex(g + 1);
    map<char, int> ids;
    vector<double> vals(g + 1);
    vector<char> name(g + 1);
    ids.insert(MP('*', 0));
    
    FOR(i, 0, g){
      cin >> k >> val >> ent;
      ids.insert(MP(k, i + 1));
      vals[i + 1] = val*100;
      conex[i + 1] = ent;
      name[i + 1] = k;
    }
    
    FOR(i, 0, g){
      FOR(j, 0, conex[i + 1].size()){
        x = ids.find(conex[i + 1][j])->s;
        grafo[i + 1].PB(x);
        grafo[x].PB(i + 1);
      }
    }
    
    deque<int> q;
    q.PB(0);
    vector<int> seen(g + 1, INF);
    seen[0] = 0.0;
    
    while(!q.empty()){
      x = q.F();
      q.P_F();
      
      FOR(i, 0, grafo[x].size()){
        y = grafo[x][i];
        if(seen[y] > seen[x] + 1.0){
          seen[y] = 1.0 + seen[x];
          q.PB(y);
        }
      }
    }
    
    mini = 0.0, ans = 'Z';
    FOR(i, 1, g + 1){
      val = vals[i]*(pow(0.95, seen[i]));
      if(mini <= val){
        if(mini == val) ans = min(ans, name[i]);
        else ans = name[i];
        
        mini = val;
      }
    }
    
    cout << "Import from " << ans << "\n";
  }
  
  return 0;
}
