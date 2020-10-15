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
  int ele, dest, x, nodo, y, ad, val;
  string ent, num;
  
  while(cin >> ele >> dest){
    vector<vector<int> > grafo(100), pisos(ele), acc(ele, vector<int> (100));
    vector<int> ts(ele);
    
    FOR(i, 0, ele) cin >> ts[i];
    getline(cin, ent);
    
    FOR(i, 0, ele){
      getline(cin, ent);
      FOR(j, 0, ent.size()){
        num = "";
        if(!isspace(ent[j])){
          num += ent[j];
          j++;
          if(!isspace(ent[j])){
            num += ent[j];
            j++;
          }
        }
        
        pisos[i].PB(stoi(num));
      }
    }
    
    FOR(i, 0, ele){
      FOR(j, 0, pisos[i].size()){
        x = pisos[i][j];
        acc[i][x] = 1;
        FOR(k, j + 1, pisos[i].size()){
          y = pisos[i][k];
          grafo[x].PB(y);
          grafo[y].PB(x);
        }
      }
    }
    
    priority_queue<pair<ll, int> > q;
    q.push(MP(0, 0));
    vector<vector<ll> > seen(100, vector<ll> (ele, INF));
    vector<int> vistos(100);
    FOR(i, 0, ele) seen[0][i] = 0;
    
    while(!q.empty()){
      nodo = q.top().s;
      q.pop();
      
      if(vistos[nodo]) continue;
      vistos[nodo] = 1;
      
      FOR(j, 0, ele){
        if(!acc[j][nodo]) continue;
        
        FOR(i, 0, grafo[nodo].size()){
          x = grafo[nodo][i];
          if(vistos[x] or !acc[j][x]) continue;
          
          FOR(k, 0, ele){
            ad = 0;
            val = abs(nodo - x);
            if(k != j) ad = 60;
            if(seen[x][k] > seen[nodo][j] + ts[j]*val + ad){
              seen[x][k] = seen[nodo][j] + ts[j]*val + ad;
              q.push(MP(-seen[x][k], x));
            }
          }
        }
      }
    }
    
    ll mini = INF;
    
    FOR(i, 0, ele) mini = min(mini, seen[dest][i]);
    
    if(mini == INF) cout << "IMPOSSIBLE\n";
    else cout << mini << "\n";
  }
  
  return 0;
}
