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
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int fn(int n){
  if(n == 1) return 1;
  else{
    if(n%2){
      return 1 + fn(3*n + 1);
    }
    else{
      return 1 + fn(n/2);
    }
  }
}

int main(){
  int a, b, maxi, veces;
  
  while(cin >> a >> b){
    cout << a << " " << b << " ";
    maxi = MINF;
    
    FOR(i, min(a, b), max(a, b) + 1){
      veces = fn(i);
      if(veces > maxi) maxi = veces;
    }
    
    cout << maxi << "\n";
  }
  
  return 0;
}
