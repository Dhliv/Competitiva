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

  int t, n, l, r; cin >> t;

  while(t--){
    cin >> n;
    l = 0;
    r = n - 1;

    if(n == 1){
      cout << "1\n";
      continue;
    }

    if(n%2 & 1){
      cout << "-1\n";
      continue;
    }

    bool turn = 1;
    l = 1;
    cout << n;
    int cr = 0, ds;
    while(l <= r){
      if(turn) ds = r--;
      else ds = l++;

      if(cr < ds) cout << " " << ds - cr;
      else cout << " " << (n - cr + ds);
      cr = ds;
      turn = 1 - turn;
    }
    cout << "\n";
  }
 
  return 0;
}