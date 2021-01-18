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
  int n, a, b, cont;
  
  while(cin >> n, n){
    a = b = cont = 0;
    
    FOR(i, 0, 32){
      if(n & (1 << i)){
        if(cont%2) b += (1 << i); 
        else a += (1 << i);
        cont++;
      }
    }
    
    cout << a << " " << b << "\n";
  }
  
  return 0;
}