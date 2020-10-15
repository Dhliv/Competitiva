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

int datos = 100000;
vector<int> all(datos+1);

int main() {
  int n, k, aux, peNe;
  cin >> n>> k; 
  vector<int> peso;
  vector< map<int, int> > grafo(n);
  for(int i=0; i<n; i++){
    cin>>aux;
    peso.PB(aux);
  }

  for(int i=0;i<n;i++){
    for(int j=i+1; j<=i+k and j<n; j++){
      peNe = abs(peso[i]-peso[j]);
      grafo[i][j] = peNe;
    }
  }

  int nodo;
  deque<int> dq;
  vector<int> seen(n, INF);
  dq.PB(0);
  seen[0] = 0;

  while(!dq.empty()){
    nodo = dq.F();
    dq.P_F();
    
    if(nodo != n-1){
      forit(x, grafo[nodo]){
        if(seen[x->first] == INF){
          seen[x->first] = x->second + seen[nodo];
          dq.PB(x->first);
        }else
          seen[x->first]= min(seen[x->first], seen[nodo] + x->second);
      }
    }
  }
  
  cout << seen[n-1] << "\n";

  return 0;
}