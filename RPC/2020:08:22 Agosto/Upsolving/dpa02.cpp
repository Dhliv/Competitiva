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
  int cases, lim = 1000000, cont;
  ll n, m, ans, sum, mul;
  
  vector<int> prims, seen(lim + 1);
  
  FOR(i, 2, lim + 1){
    if(!seen[i]){
      prims.PB(i);
      for(int j = i; j < lim + 1; j += i) seen[j] = 1;
    }
  }
  
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    vector<pair<int, int> > nums;
    m = n;
    
    for(int i = 0; i < prims.size() and m > 1; i++){
      if(m%prims[i] == 0){
        cont = 0;
        
        while(m%prims[i] == 0){
          m /= prims[i];
          cont++;
        }
        nums.PB(MP(prims[i], cont));
      }
    }
    
    if(m > 1) nums.PB(MP(m, 1));
    
    ans = 1;
    FOR(i, 0, nums.size()){
      sum = 0;
      mul = 1;
      FOR(j, 0, nums[i].s + 1){
        sum += mul;
        mul *= nums[i].f;
      }
      ans *= sum;
    }
    
    ans -= n;
    
    if(ans > n) cout << "abundant\n";
    else if(ans == n) cout << "perfect\n";
    else cout << "deficient\n";
  }
  
  return 0;
}