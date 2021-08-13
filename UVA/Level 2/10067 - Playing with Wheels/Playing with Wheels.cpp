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

  int t, n, m, x, y, ini, dest, add, left;
  cin >> t;

  FOR(ab, 0, t){
    vector<int> s(10000, INF);
    vector<bool> fb(10000);

    FOR(i, 0, 2){
      x = 0;
      m = 1000;
      FOR(j, 0, 4){
        cin >> y;
        x += y*m;
        m /= 10;
      }

      if(i == 0) ini = x;
      else dest = x;
    }

    cin >> n;
    FOR(i, 0, n){
      x = 0;
      m = 1000;
      FOR(j, 0, 4){
        cin >> y;
        x += y*m;
        m /= 10;
      }

      fb[x] = 1;
    }

    deque<int> q;
    s[ini] = 0;
    q.PB(ini);

    while(!q.empty()){
      x = q.F();
      q.P_F();
      m = 1000;
      add = 0;
      left = x;

      FOR(i, 0, 4){
        FOR(j, 0, 2){
          if(j & 1) y = (left + m)%(m*10);
          else y = (left - m + m*10)%(m*10);
          y += add;

          if(s[y] == INF and !fb[y]){
            s[y] = s[x] + 1;
            q.PB(y);
          }
        }

        add += (left/m)*m;
        left %= m;
        m /= 10;
      }
    }

    cout << (s[dest] == INF ? -1 : s[dest]) << "\n";
  }
  
  return 0;
}
