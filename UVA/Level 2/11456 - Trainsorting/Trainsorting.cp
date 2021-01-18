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

int look(int d, int l, deque<int> &q){
  int low = 0, high = l, mid;
  
  while(low <= high){
    mid = (high + low)/2;
    
    if(q[mid] > d) low = mid + 1;
    else high = mid - 1;
  }
  
  return low;
}

int main(){
  int n, k, pos, cases, maxi;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    deque<int> l(n), li(n), q, pf, pi;
    
    FOR(i, 0, n){
      cin >> k;
      q.PF(k);
    }
    
    k = 0;
    FOR(i, 0, n){
      pos = look(q[i], k, l);
      pf.PF(pos + 1);
      l[pos] = q[i];
      
      if(pos == k) k++;
    }
    
    k = 0;
    FOR(i, 0, n){
      pos = lower_bound(li.begin(), li.begin() + k, q[i]) - li.begin();
      pi.PF(pos + 1);
      li[pos] = q[i];
      
      if(pos == k) k++;
    }
    
    maxi = 0;
    FOR(i, 0, n) maxi = max(maxi, pf[i] + pi[i] - 1);
    
    cout << maxi << "\n";
  }
  
  return 0;
}