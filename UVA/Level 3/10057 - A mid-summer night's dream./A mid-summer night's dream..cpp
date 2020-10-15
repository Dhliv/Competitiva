#include <bits/stdc++.h>
#define INF 1000000000
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
  ll n, valor, datos, enEntr;
  
  while(cin >> n){
    vector<int> v(n), hash(70000);
    enEntr = datos =  0;
    
    FOR(i, 0, n){
      cin >> v[i];
      hash[v[i]] += 1;
    }
    
    sort(v.begin(), v.end());
    
    valor = v[(n-1)/2];
    
    if(n%2)
      cout << valor << " " << hash[valor] << " " << 1 << "\n";
    else{
      
      if(valor != v[n/2])
        enEntr = hash[valor] + hash[v[n/2]];
      else
        enEntr = hash[valor];
      
      datos = 1 + v[n/2] - valor;
      cout << valor << " " << enEntr << " " << datos << "\n";
    }
  }

  return 0;
}