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
  int n, x, y, target;
  bool app;

  while(t--){
    cin >> n >> target;
    app = (n == target);
    deque<int> q(1, n);

    while(!q.empty()){
      x = q.F(); q.P_F();

      if(x%3 != 0) continue;
      y = x/3;
      x = (2*x)/3;
      if(x == target or y == target){
        app = 1;
        break;
      }

      if(x > target) q.PB(x);
      if(y > target) q.PB(y);
    }

    cout << (app ? "YES" : "NO") << "\n";
  }
 
  return 0;
}