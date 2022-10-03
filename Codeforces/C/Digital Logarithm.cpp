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

  int t; cin >> t;
  int n, ans, x, y;
  string a, b;

  FOR(ab, 0, t){
    cin >> n;
    ans = 0;
    priority_queue<int> p, q;
    FOR(i, 0, n){
      cin >> x;
      p.push(x);
    }

    FOR(i, 0, n){
      cin >> x;
      q.push(x);
    }

    while(!q.empty()){
      x = p.top(); p.pop();
      y = q.top(); q.pop();

      if(x == y) continue;
      if(x > y) x = to_string(x).size();
      else y = to_string(y).size();

      q.push(y);
      p.push(x);
      ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}