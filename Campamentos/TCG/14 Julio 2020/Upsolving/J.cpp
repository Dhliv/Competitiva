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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

ll n, k, maxt;

ll op(ll dat){
  ll m = (k - 1) - dat, res;
  res = maxt - (m*(m + 1)/2);
  return res;
}

ll bus(){
  ll low = 1, high = k - 1, mid;
  
  while(low <= high){
    mid = (low + high)/2;
    if(op(mid) >= n) high = mid - 1;
    else low = mid + 1;
  }
  
  return low;
}

int main(){
  cin >> n >> k;
  maxt = k*(k + 1)/2 - (k - 1);
  
  if(n > maxt) cout << "-1\n";
  else if(n == 1) cout << 0 << "\n";
  else cout << bus() << "\n";
  
  return 0;
}