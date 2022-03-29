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
 
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, au, u, d, x; cin >> n >> au;

  u = d = 0;
  FOR(i, 0, n){
    cin >> x;

    if(x + au == x*2) continue;

    if(x + au > x*2) u++;
    else d++;
  }

  if(u == d) cout << "0\n";
  else if(u > d) cout << "1\n";
  else cout << "2\n";

  return 0;
}
