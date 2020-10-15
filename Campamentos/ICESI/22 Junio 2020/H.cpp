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

bool prime(int i){
    int aux = sqrt(i)+1;
    while(aux--){
        if(aux != 1 and aux and i%aux == 0) return false;
    }
    return true;
}

int main() {
  vector<string> prims;
  vector<vector<int> > grafo(10000);
  int cont;
	for(int i=1001; i<9999; i++){
	    if(prime(i)){
        prims.PB(to_string(i));
      }
	}

  FOR(i, 0, prims.size()){
    FOR(j, 0, prims.size()){
      if(i != j){
        cont = 0;
        FOR(k, 0, 4){
          if(prims[i][k] == prims[j][k])
            cont++;
        }
        if(cont >= 3)
          grafo[stoi(prims[i])].PB(stoi(prims[j]));
      }
    }
  }
  
  int cases, a, b, nodo;
  cin >> cases;
  
  FOR(i, 0, cases){
    cin >> a >> b;
    vector<int> seen(10000, INF);
    deque<int> dq;
    seen[a] = 0;
    dq.PB(a);
    
    if(a == b)
      cout << 0 << "\n";
    else{
      while(!dq.empty()){
        nodo = dq.F();
        dq.P_F();
        
        FOR(i, 0, grafo[nodo].size()){
          if(seen[grafo[nodo][i]] == INF){
            seen[grafo[nodo][i]] = seen[nodo] + 1;
            dq.PB(grafo[nodo][i]);
          }
        }
      }
      
      cout << seen[b] << "\n";
    }
  }

	return 0;
}