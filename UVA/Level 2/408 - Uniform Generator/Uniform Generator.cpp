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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int a, b, aux, decs1, decs2;
  
  while(cin >> a >> b){
    
    decs1 = 0;
    FOR(i, 0, 11){
      if(a/(pow(10, i)) >= 1) decs1++;
    }
    
    decs2 = 0;
    FOR(i, 0, 11){
      if(b/(pow(10, i)) >= 1) decs2++;
    }
    
    FOR(i, 0, 10 - decs1)
      cout << " ";
      
    cout << a;
    
    FOR(i, 0, 10 - decs2)
      cout << " ";
    
    cout << b << "    ";
    
    if(__gcd(a, b) == 1)
      cout << "Good Choice\n\n";
    else
      cout << "Bad Choice\n\n";
  }
  
  return 0;
}