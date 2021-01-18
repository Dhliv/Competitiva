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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, n, ans, maxi, pos;
  bool able;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    maxi = MINF;
    vector<int> dat(n);
    able = false;
    
    FOR(i, 0, n){
      cin >> dat[i];
      if(dat[i] > maxi){
        maxi = dat[i];
        pos = i;
      }
    }
    
    FOR(i, pos, n){
      if(dat[i] == maxi){
        if(i - 1 >= 0 and maxi > dat[i - 1]){
          able = true;
          ans = i + 1;
          break;
        }else if(i + 1 < n and maxi > dat[i + 1]){
          able = true;
          ans = i + 1;
          break;
        }
      }
    }
    
    if(able) cout << ans << "\n";
    else cout << "-1\n";
  }
  
  return 0;
}