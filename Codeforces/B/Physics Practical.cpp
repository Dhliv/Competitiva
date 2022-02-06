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

  ifstream cin;
  cin.open("input.txt");
  ofstream cout("output.txt");

  int n; cin >> n;
  vector<int> p(n + 1);
  FOR(i, 0, n) cin >> p[i];
  p[n] = INF;

  sort(p.begin(), p.end());

  int ans = INF, ax;

  FOR(i, 0, n - 1){
    ax = upper_bound(p.begin() + i + 1, p.end(), p[i]*2) - p.begin();
    ax--;
    ans = min(ans, (int)i + n - 1 - ax);
  }

  cout << ans << "\n";

  return 0;
}
