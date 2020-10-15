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
  ll res;
  int n, a, b, cur, s;
  
  while(cin >> n, n){
    cin >> a >> b;
    s = 0;
    map<int, int> nums;
    cur = 0;
    nums.insert(MP(cur, s++));
    res = pow(cur, 2);
    res = (a*(res%n))%n;
    cur = (res + b)%n;
    
    while(nums.find(cur) == nums.end()){
      nums.insert(MP(cur, s++));
      res = ((ll)cur)*((ll)cur);
      res = (a*(res%n))%n;
      cur = (res + b)%n;
    }
    
    res = n - (nums.size() - nums.find(cur)->s);
    
    cout << res << "\n";
  }
  
  return 0;
}
