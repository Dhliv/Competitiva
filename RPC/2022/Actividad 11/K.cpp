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

  int a, b, c, d; cin >> a >> b >> c >> d;
  int ymin = ceil(c/b);

  FOR(i, 0, 1000000){
    if((d + b*(ymin + i))%a == 0){
      int trucks = (d + b*(ymin + i))/a;
      int boats = ymin + i;
      cout << "We need " << trucks << (trucks == 1 ? " truck" : " trucks");
      cout << " and " << boats << (boats == 1 ? " boat" : " boats") << ".\n";
      return 0;
    }
  }

  cout << "No solution.\n";
  
  return 0;
}