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

  int t, a, b, c, n;
  cin >> t;

  FOR(ab, 0, t){
    cin >> a >> b >> c;
    n = 2*abs(a - b);

    if(a > n or b > n or c > n) cout << "-1\n";
    else cout << (c > n/2 ? (c - n/2) : (c + n/2)) << "\n";
  }

  return 0;
}