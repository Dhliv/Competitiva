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
  int cases, tuplas;
  bool ciclo;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> tuplas;
    vector<int> v(tuplas), zeros(tuplas);
    map<vector<int>, int> dp;
    dp.insert(MP(v, 0));
    ciclo = false;
    
    FOR(i, 0, tuplas)
      cin >> v[i];
      
    while(true){
      vector<int> aux(tuplas);
      
      FOR(i, 1, tuplas)
        aux[i-1] = abs(v[i] - v[i-1]);
      aux[tuplas-1] = abs(v[tuplas-1] - v[0]);
      
      if(dp.find(aux) == dp.end())
        dp.insert(MP(aux, 0));
      else{
        if(aux != zeros)
          ciclo = true;
        break;
      }
      v.swap(aux);
    }
    
    if(ciclo)
      cout << "LOOP\n";
    else
      cout << "ZERO\n";
  }
  
  return 0;
}