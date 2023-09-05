#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n;

  while(t--){
    cin >> n;
    vector<int> p(n + 1); FOR(i, 0, n) cin >> p[i];
    p[n] = INF;
    sort(p.begin(), p.end());

    int x = p[0];
    int cnt = 1;
    vector<int> ans(n + 1);
    FOR(i, 1, n + 1){
      if(x != p[i]){
        for(int j = x; j <= n; j += x) ans[j] += cnt;
        x = p[i];
        cnt = 1;
      }else cnt++;
    }

    int maxi = 0;
    FOR(i, 0, n + 1) maxi = max(maxi, ans[i]);

    cout << maxi << "\n";
  }
 
  return 0;
}