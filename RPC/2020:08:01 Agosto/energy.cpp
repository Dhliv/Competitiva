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
  int ta, td, n, cost, consu;
  bool pass;
  cin >> ta >> td >> n;
  
  FOR(a, 0, n){
    cin >> consu;
    pass = false;
    if(consu > 1000) pass = true;
    
    if(pass) cost = 1000*ta + td*(consu - 1000);
    else cost = ta*consu;
    
    cout << consu << " " << cost << "\n";
  }
  
  return 0;
}