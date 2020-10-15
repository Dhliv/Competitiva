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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int main() {
  int cases, h, w, aux;
  pair<int, int> nodo;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> h >> w;
    vector<string> data(h);
    
    FOR(i, 0, h)
      cin >> data[i];
      
    deque<pair<int, int> > pq, will;
    pq.PB(MP(0, 0));
    vector<vector<int> > seen(h, vector<int> (w, INF));
    seen[0][0] = 0;
    
    while(true){
      
      while(!pq.empty()){
        nodo = pq.F();
        pq.P_F();
        
        if(nodo.f + 1 < h){
          
          if(data[nodo.f][nodo.s] != data[nodo.f + 1][nodo.s]){
            if(seen[nodo.f + 1][nodo.s] > seen[nodo.f][nodo.s] + 1){
              seen[nodo.f + 1][nodo.s] = seen[nodo.f][nodo.s] + 1;
              will.PB(MP(nodo.f + 1, nodo.s));
            }
          }
          else if(seen[nodo.f + 1][nodo.s] > seen[nodo.f][nodo.s]){
            seen[nodo.f + 1][nodo.s] = seen[nodo.f][nodo.s];
            pq.PB(MP(nodo.f + 1, nodo.s));
          }
        }
        
        if(nodo.f - 1 >= 0){
          
          if(data[nodo.f][nodo.s] != data[nodo.f - 1][nodo.s]){
            if(seen[nodo.f - 1][nodo.s] > 1 + seen[nodo.f][nodo.s]){
              will.PB(MP(nodo.f - 1, nodo.s));
              seen[nodo.f - 1][nodo.s] = 1 + seen[nodo.f][nodo.s];
            }
          }
          else if(seen[nodo.f - 1][nodo.s] > seen[nodo.f][nodo.s]){
            seen[nodo.f - 1][nodo.s] = seen[nodo.f][nodo.s];
            pq.PB(MP(nodo.f - 1, nodo.s));
          }
        }
        
        if(nodo.s + 1 < w){
          
          if(data[nodo.f][nodo.s] != data[nodo.f][nodo.s + 1]){
            if(seen[nodo.f][nodo.s + 1] > 1 + seen[nodo.f][nodo.s]){
              will.PB(MP(nodo.f, nodo.s + 1));
              seen[nodo.f][nodo.s + 1] = 1 + seen[nodo.f][nodo.s];
            }
          }
          else if(seen[nodo.f][nodo.s + 1] > seen[nodo.f][nodo.s]){
            seen[nodo.f][nodo.s + 1] = seen[nodo.f][nodo.s];
            pq.PB(MP(nodo.f, nodo.s + 1));
          }
        }
        
        if(nodo.s - 1 >= 0){
          
          if(data[nodo.f][nodo.s] != data[nodo.f][nodo.s - 1]){
            if(seen[nodo.f][nodo.s - 1] > 1 + seen[nodo.f][nodo.s]){
              will.PB(MP(nodo.f, nodo.s - 1));
              seen[nodo.f][nodo.s - 1] = 1 + seen[nodo.f][nodo.s];
            }
          }
          else if(seen[nodo.f][nodo.s - 1] > seen[nodo.f][nodo.s]){
            seen[nodo.f][nodo.s - 1] = seen[nodo.f][nodo.s];
            pq.PB(MP(nodo.f, nodo.s - 1));
          }
        }
      }
      
      if(will.empty() or seen[h - 1][w - 1] != INF) break;
      
      pq.swap(will);
    }
    
    cout << seen[h - 1][w - 1] << "\n";
  }

	return 0;
}