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
#define tri pair<int, pair<int, int> >

using namespace std;

int main(){
  int n, cont, a;
  
  while(cin >> n){
    vector<int> datos(4);
    cont = 0;
    
    FOR(i, 0, 32){
      datos[cont] += (n & (1 << i)) ? (1 << i%8) : 0;
      if((i + 1)%8 == 0) cont++;
    }
    
    a = 0;
    FORI(i, 3, 0){
      FOR(j, 0, 8) a += (datos[i] & (1 << j)) ? (1 << (j + (3 - i)*8)) : 0;
    }
    
    cout << n << " converts to " << a << "\n";
  }
  
  return 0;
}