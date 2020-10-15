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
#define For(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main() {
  ll n, a=2018, m=4;
  cin >> n;
  while(true){
    if(n == a){ cout << "yes" << endl; break;}
    if(n<a){cout << "no" <<endl; break;}
    m+=2;
    a+=2;
    if(m > 12){ m=1; a++;}
    
  }
  

  return 0;
}