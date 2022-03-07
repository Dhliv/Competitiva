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
#define MAX 100001
 
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, maxi, act, ans; cin >> t;
  int pos[MAX], p[MAX];
  bool has[MAX];

  FOR(ab, 0, t){
    cin >> n;
    ans = 0;
    act = 1;
    maxi = 0;

    FOR(i, 0, n){
      cin >> p[i];
      pos[p[i]] = i;
      has[p[i]] = 0;
    }

    FOR(i, 0, n){
      has[p[i]] = 1;
      maxi = max(maxi, p[i]);

      while(act <= n and has[act]) act++;

      if(maxi > act){
        while(maxi > act){
          FOR(j, i + 1, pos[act] + 1){
            has[p[j]] = 1;
            maxi = max(maxi, p[j]);
          }

          i = pos[act];
          while(act <= n and has[act]) act++;
        }
      }
      ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}
