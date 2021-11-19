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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll d, k, ans, l, r, res, lleva;

  while(cin >> d >> k, d + k){
    vector<int> s(2*k), sq(2*k);
    const int dz = 10;
    const int dv = (d*d)/dz, dm = (d*d)%dz;
    bool did = 0;
    l = 1;
    if(l == k) did = 1;
    
    FOR(i, 0, 2*k){
      sq[i] = l;
      if(did) l--;
      else l++;

      if(l == k) did = 1;
    }

    l = 0;
    r = 2*k - 1;
    ans = lleva = 0;

    FOR(i, 0, 2*k){
      res = sq[l++]*dm + sq[r--]*dv + lleva;
      ans += res%dz;
      lleva = res/dz;
    }

    while(lleva){
      ans += lleva%10;
      lleva /= dz;
    }

    cout << ans << "\n";
  }

  return 0;
}