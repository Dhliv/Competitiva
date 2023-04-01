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

int k, n;

bool able(int dif) {
  int acum = 1;
  if(dif >= k) return false;

  FOR(i, 1, dif + 1){
    acum += i;
  }

  if(acum > n) return false;

  int maxi = dif + 1;
  FOR(i, acum + 1, n + 1) maxi++;
  return maxi >= k;
}

int bs(){
  int l = 0, r = k - 1, m;

  while(l <= r){
    m = (l + r)/2;

    if(able(m)) l = m + 1;
    else r = m - 1;
  }

  if(!able(l)) l--;

  return l;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int ans, acum;

  while(t--){
    cin >> k >> n;
    ans = bs();
    //cout << "ans: " << ans << "\n";
    acum = 1;

    cout << 1;
    FOR(i, 1, ans + 1){
      acum += i;
      cout << " " << acum;
    }

    FOR(i, 0, k - ans - 1) cout << " " << acum + i + 1;

    cout << "\n";
  }

  return 0;
}