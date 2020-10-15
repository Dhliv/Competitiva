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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  ll n, num, ans = 0, acu = 10;
  vector<int> cont(20);
  cin >> n;
  
  FOR(i, 0, n){
    cin >> num;
    FOR(j, 0, 20){
      if(num & 1 << j)
        cont[j]++;
    }
  }
  
  while(acu != 0){
    acu = 0;
    for(int i = 19; i >= 0; i--){
      if(cont[i]){
        acu += 1 << i;
        cont[i]--;
      }
    }
    ans += acu * acu;
  }
  
  cout << ans << "\n";
  
  return 0;
}