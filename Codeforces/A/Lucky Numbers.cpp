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

int getMax(int n){
  int maxi = 0, mini = 9, x;

  while(n){
    x = n%10;
    maxi = max(x, maxi);
    mini = min(mini, x);
    n /= 10;
  }

  return maxi - mini;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int l, r;

  while(t--){
    cin >> l >> r;

    int ans = 0;
    int num = l, x;
    FOR(i, 0, 100){
      if(i + l > r) break;
      if(i + l < 10) continue;

      x = getMax(i + l);
      if(x > ans){
        ans = x;
        num = i + l;
      }
    }

    cout << num << "\n";
  }

  return 0;
}