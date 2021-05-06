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
  
  int t, n, x, bef;
  bool s;
  string a;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n >> a;
    vector<int> p(26);
    s = false;
    
    bef = a[0] - 'A';
    p[bef] = 1;
    FOR(i, 1, n){
      x = a[i] - 'A';
      if(p[x] and bef != x) s = true;
      bef = x;
      p[x] = 1;
    }
    
    if(s) cout << "NO\n";
    else cout << "YES\n";
  }
  
  return 0;
}