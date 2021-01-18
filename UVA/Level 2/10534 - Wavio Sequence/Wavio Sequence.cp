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
  int n, k, pos, maxi, lim, dif;
  while(cin >> n){
    deque<int> q(n), qi, pf(n), pi(n), l(n), li(n);
    lim = n/2;
    
    FOR(i, 0, n){
      cin >> q[i];
      qi.PF(q[i]);
    }
    
    k = 0;
    FOR(i, 0, n){
      pos = lower_bound(l.begin(), l.begin() + k, q[i]) - l.begin();
      pf[i] = pos + 1;
      l[pos] = q[i];
      
      if(pos == k) k++;
    }
    
    k = 0;
    FOR(i, 0, n){
      pos = lower_bound(li.begin(), li.begin() + k, qi[i]) - li.begin();
      pi[i] = pos + 1;
      li[pos] = qi[i];
      
      if(pos == k) k++;
    }
    
    maxi = 0;
    FOR(i, 0, n){
      dif = abs(pf[i] - pi[(n - 1) - i]);
      maxi = max(maxi, pf[i] + pi[(n - 1) - i] - (1 + dif));
    }
    
    cout << maxi << "\n";
  }
  
  return 0;
}