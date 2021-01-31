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

using namespace std;

ll cases, it, lp, hp, ct, op, maxi, aux;

ll f(ll ct){
  return min(ct*hp, (it - ct)*lp);
}

int main(){
  cin >> cases;
  
  FOR(i, 0, cases){
    cin >> it >> lp >> hp;
    ct = (it*lp)/(hp + lp);
    maxi = f(ct);
    
    if(f(ct + 1) >= maxi) ct++;
    
    cout << ct << "\n";
  }

  return 0;
}