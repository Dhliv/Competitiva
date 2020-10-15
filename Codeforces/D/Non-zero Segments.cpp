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
  int n, ans = 0, pos = 0;
  ll p;
  bool find;
  cin >> n;
  vector<ll> data(n);
  
  FOR(i, 0, n) cin >> data[i];
  
  while(pos < n){
    set<ll> pre;
    p = data[pos];
    find = false;
    pre.insert(p);
    
    FOR(i, pos + 1, n){
      p += data[i];
      if(pre.find(p) != pre.end() or p == 0){
        ans++;
        pos = i;
        find = true;
        break;
      }else{
        pre.insert(p);
      }
    }
    
    if(!find) break;
  }
  
  cout << ans << "\n";
  
  return 0;
}