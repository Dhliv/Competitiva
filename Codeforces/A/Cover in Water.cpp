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

  int t; cin >> t;
  int n, ans, x, sum;

  while(t--){
    cin >> n;
    string s; cin >> s;
    ans = x = sum = 0;
    s.PB('#');
    FOR(i, 0, n + 1){
      if(s[i] == '#'){
        if(sum > 2){
          ans = 2;
          break;
        }

        ans += sum;
        sum = 0;
        continue;
      }

      sum++;
    }

    cout << ans << "\n";
  }
  
  return 0;
}