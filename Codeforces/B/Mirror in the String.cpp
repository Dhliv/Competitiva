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

  int t; cin >> t;
  int n, reps;
  string a, ans;

  FOR(ab, 0, t){
    cin >> n >> a;
    ans = "";
    ans.PB(a[0]);
    reps = 1;

    FOR(i, 1, n){
      if(a[i] < a[i - 1]){
        ans.PB(a[i]);
        reps = 1;
      }
      else if(a[i] == a[i - 1] and ans.size() > 1){
        if(ans[ans.size() - reps - 1] > a[i]){
          ans.PB(a[i]);
          reps++;
        }else  break;
      }
      else break;
    }

    int size = ans.size();
    FORI(i, size - 1, 0){
      ans.PB(ans[i]);
    }

    cout << ans << "\n";
  }

  return 0;
}