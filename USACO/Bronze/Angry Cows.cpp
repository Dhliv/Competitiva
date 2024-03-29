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

  ifstream cin("angry.in");
  ofstream cout("angry.out");

  int n; cin >> n;
  vector<int> p(n);
  FOR(i, 0, n) cin >> p[i];
  sort(p.begin(), p.end());

  int ans = 0, act, t, acum, last;
  bool exp;
  FOR(i, 0, n){
    t = 1;
    act = 0;
    exp = false;
    last = i;
    FOR(j, i + 1, n){
      if(p[j] <= p[last] + t){
        act++;
        exp = 1;
      }else{
        if(exp){
          exp = 0;
          t++;
          j--;
          last = j;
        }else break;
      }
    }

    acum = act;
    act = 0;
    t = 1;
    exp = 0;
    last = i;
    FORI(j, i - 1, 0){
      if(p[j] >= p[last] - t){
        act++;
        exp = 1;
      }else{
        if(exp){
          exp = 0;
          t++;
          j++;
          last = j;
        }else break;
      }
    }

    ans = max(ans, acum + act);
  }

  cout << ans + 1 << "\n";

  return 0;
}
