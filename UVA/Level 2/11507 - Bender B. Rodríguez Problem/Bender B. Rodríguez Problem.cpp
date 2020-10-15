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
  vector<map<int, int> > grafo(6);
  vector<string> aNod{"+x", "-x", "+y", "-y", "+z", "-z"};

  /*
    +x -> 0
    -x -> 1
    +y -> 2
    -y -> 3
    +z -> 4
    -z -> 5
  */
  
  FOR(i, 2, 6)
    grafo[0].insert(MP(i, i));
  
  grafo[1].insert(MP(2, 3));
  grafo[1].insert(MP(3, 2));
  grafo[1].insert(MP(4, 5));
  grafo[1].insert(MP(5, 4));
  
  grafo[2].insert(MP(2, 1));
  grafo[2].insert(MP(3, 0));
  grafo[2].insert(MP(4, 2));
  grafo[2].insert(MP(5, 2));
  
  grafo[3].insert(MP(2, 0));
  grafo[3].insert(MP(3, 1));
  grafo[3].insert(MP(4, 3));
  grafo[3].insert(MP(5, 3));
  
  grafo[4].insert(MP(2, 4));
  grafo[4].insert(MP(3, 4));
  grafo[4].insert(MP(4, 1));
  grafo[4].insert(MP(5, 0));
  
  grafo[5].insert(MP(2, 5));
  grafo[5].insert(MP(3, 5));
  grafo[5].insert(MP(4, 0));
  grafo[5].insert(MP(5, 1));
  
  int L, nodo;
  string ari, destino;
  
  while(cin >> L, L){
    nodo = 0;
      
    FOR(i, 0, L-1){
      cin >> ari;
      if(ari != "No"){
        FOR(a, 0, 6){
          if(aNod[a] == ari)
            nodo = grafo[nodo].find(a)->second;
        }
      }
    }
    
    cout << aNod[nodo] + "\n";
  }
  
  return 0;
}