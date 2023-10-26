#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n; cin >> n;
  int x = 0;

  while(n > 0){
    int a = n%10;
    n /= 10;
    if(a == 7 or a == 4) x++;
  }

  bool able = x > 0;
  while(x > 0){
    int a = x%10;
    x /= 10;
    if(a != 4 and a != 7){
      able = false;
      break;
    }
  }

  cout << (able ? "YES" : "NO") << "\n";

  return 0;
}