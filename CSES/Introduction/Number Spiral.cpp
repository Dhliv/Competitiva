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
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t, x, y, d, st;
  cin >> t;

  FOR(ab, 0, t){
    cin >> x >> y;
    d = max(x, y);
    st = (d - 1)*(d - 1) + 1;

    if(x == d){
      if(d & 1) st += (y - 1);
      else st += (2*x - y - 1);
    }else{ // y == d
      if(d & 1) st += (2*y - x - 1);
      else st += (x - 1);
    }

    cout << st << "\n";
  }

  return 0;
}
