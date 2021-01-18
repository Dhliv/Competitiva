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
  int cases, n, l, r;
  bool lf;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n;
    deque<int> q(n), a(n);
    
    FOR(i, 0, n) cin >> q[i];
    l = 0; r = n - 1;
    lf = true;
    
    FOR(i, 0, n){
      if(lf){
        a[i] = q[l];
        l++;
        lf = false;
      }else{
        a[i] = q[r];
        r--;
        lf = true;
      }
    }
    
    FOR(i, 0, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << "\n";
  }
  
  return 0;
}