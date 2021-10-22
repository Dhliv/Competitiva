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

  int t, n, ans, left, d, l; cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    deque<int> q(n), o(n);

    FOR(i, 0, n){
      cin >> q[i];
      o[i] = q[i];
    }

    sort(o.begin(), o.end());

    deque<pair<int, pair<int, int> > > p;
    left = n;
    ans = 0;
    l = 1;
    while(left > 0){
      d = 0;
      while(o.F() != q.F()){
        d++;
        q.PB(q.F());
        q.P_F();
      }

      if(d){
        ans++;
        p.PB(MP(d, MP(l, n)));
      }

      o.P_F();
      q.P_F();
      left--;
      l++;
    }

    cout << ans << "\n";
    while(!p.empty()){
      cout << p.F().s.f << " " << p.F().s.s << " " << p.F().f << "\n";
      p.P_F();
    }
  }
 
  return 0;
} 