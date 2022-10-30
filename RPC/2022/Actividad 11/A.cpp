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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b, c, d, e, ans1, ans2;
  ans1 = ans2 = 0;

  FOR(i, 0, 5){
    cin >> a;
    if(i == 0) ans1 += a*6;
    else if(i == 1) ans1 += a*3;
    else if(i == 2 or i == 4) ans1 += a*2;
    else ans1 += a;
  }

  FOR(i, 0, 5){
    cin >> a;
    if(i == 0) ans2 += a*6;
    else if(i == 1) ans2 += a*3;
    else if(i == 2 or i == 4) ans2 += a*2;
    else ans2 += a;
  }

  cout << ans1 << " " << ans2 << "\n";
  
  return 0;
}