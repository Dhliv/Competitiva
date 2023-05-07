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

  int maxi, cr, x, t, n; cin >> t;

  while(t--){
    cin >> n;
    maxi = 0;
    cr = 0;

    FOR(i, 0, n){
      cin >> x;
      if(x){
        maxi = max(maxi, cr);
        cr = 0;
      }else{
        cr++;
      }
    }

    maxi = max(maxi, cr);
    cout << maxi << "\n";
  }
 
  return 0;
}