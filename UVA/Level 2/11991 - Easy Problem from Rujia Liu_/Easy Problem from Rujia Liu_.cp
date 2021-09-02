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

using namespace std;

int main(){
  int n, m, l = 1000001, d, k;
  
  while(cin >> n >> m){
    map<int, vector<int> > grafo;
    vector<int> aux(1);
    
    FOR(i, 0, n){
      cin >> d;
      if(grafo.find(d) == grafo.end()){
        aux[0] = i + 1;
        grafo.insert(MP(d, aux));
      }else grafo[d].PB(i + 1);
    }
    
    FOR(i, 0, m){
      cin >> k >> d;
      if(grafo.find(d) != grafo.end()){
        if(grafo[d].size() >= k) cout << grafo[d][k - 1] << "\n";
        else cout << "0\n";
      }else cout << "0\n";
    }
  }
  
  return 0;
}