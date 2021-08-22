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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, m, r, c, ans, x, y, k;
  deque<int> p;

  FOR(i, 1, sqrt(1000000100) + 1){
    x = (i - 1)*(i - 1) + 1;
    p.PB(x);
  }
  cin >> t;

  FOR(ab, 0, t){
    cin >> k;

    x = upper_bound(p.begin(), p.end(), k) - p.begin();
    c = x;
    x = p[x - 1];

    if(x + c - 1 >= k){
      r = k - x + 1;
    }else{
      r = c;
      x += (c - 1);
      y = k - x;
      c = r - y;
    }

    cout << r << " " << c << "\n";
  }

  return 0;
}