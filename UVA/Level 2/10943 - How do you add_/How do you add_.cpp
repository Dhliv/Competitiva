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
  ll n, k, sum, mod;
  mod = 1000000;
  
  while(cin >> n >> k, n + k){
    deque<ll> q(n + 1), aux(n + 1);
    if(k > 1){
      FORI(i, n, 0) q[i] = i + 1;
      
      while(k > 2){
        k--;
        sum = 0;
        FOR(i, 0, n + 1) sum += q[i];
        aux[n] = sum;
        FORI(i, n - 1, 0) aux[i] = (aux[i + 1] - q[i + 1]);
        FORI(i, n, 0) aux[i] = aux[i]%mod;
        aux.swap(q);
      }
      
      cout << q[n] << "\n";
    }else cout << "1\n";
  }
  
  
  return 0;
}
