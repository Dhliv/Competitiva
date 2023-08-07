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

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll a, b, x;
  int n1, n2;

  while(t--){
    a = b = 0;
    cin >> n1 >> n2;
    FOR(i, 0, n1){
      cin >> x;
      a += x;
    }

    FOR(i, 0, n2){
      cin >> x;
      b += x;
    }

    if(a > b) cout << "Tsondu\n";
    else if(b > a) cout << "Tenzing\n";
    else cout << "Draw\n";
  }
 
  return 0;
}