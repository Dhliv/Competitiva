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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, ans, a, b;

  FOR(ab, 0, t){
    cin >> n;
    ans = 1;
    cin >> a;
    FOR(i, 1, n){
      cin >> b;
      if(a > b) a -= b;
      else if(a < b){
        a = b - a;
        ans = i + 1;
      }
      else{
        cin >> a;
        ans = i + 2;
        i++;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}