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

  int n, x, c, maxi, pos;

  while(cin >> n){
    deque<int> s;
    deque<pair<int, int> > p(n);

    FOR(i, 0, n){
      cin >> x >> c;
      p[i] = MP(x, c);
    }

    sort(p.begin(), p.end());

    s.PB(p[n - 1].f);
    maxi = 0;
    pos = s[0];

    FORI(i, n - 2, 0){
      x = upper_bound(s.begin(), s.end(), p[i].f + p[i].s) - s.begin();
      if(x >= maxi){
        maxi = x;
        pos = p[i].f;
      }

      s.PF(p[i].f);
    }

    cout << pos << " " << maxi << "\n";
  }

  return 0;
}