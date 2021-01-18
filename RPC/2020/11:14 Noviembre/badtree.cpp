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
#define MAX 103
 
using namespace std;

int main(){
  int n, pi, pd;
  ll k;
  cin >> n >> k;
  
  __int128 neo = 1, low = 0, high, mitad;
  pi = 0;
  pd = n - 1;
  
  FOR(i, 1, n) neo *= 2;
  high = neo;
  
  if(n == 1){
    if(k == 1) cout << "1\n";
    else cout << "-1\n";
  }else{
    if(k > neo) cout << "-1\n";
    else{
      while(pi != pd){
        mitad = (low + high)/2;
        if(mitad < k){
          cout << pd  + 1 << " ";
          pd--;
          low = mitad;
        }else{
          cout << pi + 1 << " ";
          pi++;
          high = mitad;
        }
      }
      
      cout << pi + 1 << "\n";
    }
  }
  
  return 0;
}