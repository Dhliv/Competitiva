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

vector<ll> ps(200005);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, x;
  int l, r, m;
  ll sum, getted;

  while(t--){
    cin >> n;

    FOR(i, 1, n + 1){
      cin >> x;
      ps[i] = ps[i - 1] + x;
    }

    l = 1; r = n;
    while(l <= r){
      m = (l + r)/2;

      cout << "? " << (m - l + 1);
      FOR(i, l, m + 1) cout << " " << i;
      cout << endl;
      cin >> getted;
      sum = ps[m] - ps[l - 1];

      if(sum == getted) l = m + 1;
      else r = m - 1;
    }

    cout << "! " << l << endl;
  }
 
  return 0;
}