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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int emplo, nAmi, ami, cases, nodoIni, nodo, D, maxi, cont;
  cin >> emplo;
  vector<vector<int> > grafo(emplo);
  
  FOR(i, 0, emplo){
    cin >> nAmi;
    
    FOR(a, 0, nAmi){
      cin >> ami;
      grafo[i].PB(ami);
    }
  }

  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> nodoIni;
    vector<int> seen(emplo, INF);
    deque<int> spreading, will;
    spreading.PB(nodoIni);
    seen[nodoIni] = D = maxi = 0, cont = 1;
    
    while(true){
      
      while(!spreading.empty()){
        nodo = spreading.F();
        spreading.P_F();
        
        FOR(i, 0, grafo[nodo].size()){
          if(seen[grafo[nodo][i]] == INF){
            seen[grafo[nodo][i]] = 0;
            will.PB(grafo[nodo][i]);
          }
        }
      }
      
      if(will.empty()) break;
      
      if(will.size() > maxi){
        D = cont;
        maxi = will.size();
      }
      
      spreading.swap(will);
      cont++;
    }
    
    if(D)
      cout << maxi << " " << D << "\n";
    else
      cout << D << "\n";
  }
  return 0;
}