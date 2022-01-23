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

  int t, n, l, r, x; cin >> t;
  pair<int, int> a;

  FOR(ab, 0, t){
    cin >> n;
    set<pair<int, int> > s;
    deque<pair<int, int> > p;

    p.PB(MP(1, n));

    FOR(i, 0, n){
      cin >> l >> r;
      s.insert(MP(l, r));
    }

    while(!p.empty()){
      a = p.F();
      p.P_F();

      cout << a.f << " " << a.s << " ";

      if(a.f == a.s){
        cout << a.f << "\n";
        continue;
      }

      if(s.find(MP(a.f + 1, a.s)) != s.end()){
        p.PB(MP(a.f + 1, a.s));
        cout << a.f << "\n";
        continue;
      }

      if(s.find(MP(a.f, a.s - 1)) != s.end()){
        p.PB(MP(a.f, a.s - 1));
        cout << a.s << "\n";
        continue;
      }

      FOR(i, a.f + 1, a.s){
        if(s.find(MP(a.f, i - 1)) != s.end() and s.find(MP(i + 1, a.s)) != s.end()){
          cout << i << "\n";
          p.PB(MP(a.f, i - 1));
          p.PB(MP(i + 1, a.s));
        }
      }
    }
  }

  return 0;
}
