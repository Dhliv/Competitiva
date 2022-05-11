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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, s, w, h, ans; cin >> n;
  vector<int> p(101), start(101), fin(101);

  ans = 100;

  FOR(i, 0, n){
    cin >> s >> w >> h;

    start[s] = h;
    fin[s + w] = h;
    FOR(j, 0, w + 1) p[s + j] = h;
  }

  h = 0;
  FOR(i, 1, 101){
    if(start[i] == fin[i]){
      ans += abs(h - p[i]);
      h = p[i];
    }else{
      ans += abs(h - start[i]);
      h = start[i];
    }
  }

  cout << ans << "\n";

  return 0;
}