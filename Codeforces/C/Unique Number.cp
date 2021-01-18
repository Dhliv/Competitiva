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
  int cases, x;
  cin >> cases;
  
  FOR(b, 0, cases){
    cin >> x;
    if(x > 45) cout << "-1\n";
    else{
      deque<int> ans;
      vector<bool> hash(10, true);
      
      while(x > 0){
        FORI(i, 9, 1){
          if(x - i >= 0 and hash[i]){
            ans.PF(i);
            hash[i] = false;
            x -= i;
          }
        }
      }
      
      FOR(i, 0, ans.size()) cout << ans[i];
      cout << "\n";
    }
  }
  
  return 0;
}