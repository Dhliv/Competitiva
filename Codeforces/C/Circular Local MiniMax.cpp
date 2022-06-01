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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, x; cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    deque<int> p(n); FOR(i, 0, n) cin >> p[i];
    sort(p.begin(), p.end());

    vector<int> sol(n);
    for(int i = n - 1; i >= 0; i -= 2){
      sol[i] = p.B();
      p.P_B();
    }

    for(int i = n - 2; i >= 0; i -= 2){
      sol[i] = p.B();
      p.P_B();
    }

    bool able = true;

    FOR(i, 0, n){
      if(sol[i] > sol[(i - 1 + n)%n] and sol[i] > sol[(i + 1)%n]) continue;
      if(sol[i] < sol[(i - 1 + n)%n] and sol[i] < sol[(i + 1)%n]) continue;
      able = false;
      break;
    }

    cout << (able ? "YES" : "NO") << "\n";
    if(able){
      FOR(i, 0, n) cout << sol[i] << " ";
      cout << "\n";
    }
  }

  return 0;
}