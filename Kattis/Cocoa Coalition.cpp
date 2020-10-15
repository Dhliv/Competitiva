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
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  ll n, m, a, b;
  cin >> n >> m >> a;
  b = m*n - a;
  
  if(a%n == 0 or a%m == 0) cout << "1\n";
  else{
    if(n > m){
      FOR(i, 1, m){
        if(a%i == 0 and a <= i*n){
          cout << "2\n";
          return 0;
        }
      }
      
      FOR(i, 1, m){
        if(b%i == 0 and b <= i*n){
          cout << "2\n";
          return 0;
        }
      }
      
      cout << "3\n";
    }else{
      FOR(i, 1, n){
        if(a%i == 0 and a <= i*m){
          cout << "2\n";
          return 0;
        }
      }
      
      FOR(i, 1, n){
        if(b%i == 0 and b <= i*m){
          cout << "2\n";
          return 0;
        }
      }
      
      cout << "3\n";
    }
  }

  return 0;
}