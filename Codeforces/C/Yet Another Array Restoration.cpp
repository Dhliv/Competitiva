#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
  int cases, x, y, dif, dist, n, cont, val;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n >> x >> y;
    dif = y - x;
    vector<int> ans;
    ans.PB(x);
    ans.PB(y);
    
    FOR(i, 1, dif + 1){
      if(dif%i == 0 and (dif/i) <= (n - 1)){
        dist = i;
        break;
      }
    }
    
    n -= 2;
    
    FOR(i, 1, dif/dist){
      ans.PB(x + i*dist);
      n--;
    }
    
    val = x - dist;
    
    while(n and val >= 1){
      ans.PB(val);
      val -= dist;
      n--;
    }
    
    val = y + dist;
    while(n){
      ans.PB(val);
      val += dist;
      n--;
    }
    
    FOR(i, 0, ans.size()) cout << ans[i] << " ";
    cout << "\n";
  }
  
  return 0;
}
