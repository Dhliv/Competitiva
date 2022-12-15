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

  int n, x, ans; cin >> n;
  map<int, int> m;
  vector<int> p(n);

  ans = 1;
  int l = 0;
  FOR(i, 0, n){
    cin >> x;
    p[i] = x;
    auto it = m.find(x);
    if(it == m.end()) m.insert(MP(x, 1));
    else it->s++;

    while((--m.end())->f - m.begin()->f > 1){
      it = m.find(p[l]);
      it->s--;

      if(it->s == 0) m.erase(p[l]);
      l++;
    }

    ans = max(ans, (int) i - l + 1);
  }

  cout << ans << "\n";

  return 0;
}