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

  int t, n, num;
  ll x, res;
  const int pot = 10;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    vector<ll> vcs(1 << 10);

    FOR(i, 0, n){
      cin >> x;
      num = 0;

      while(x != 0){
        num |= 1 << (x%pot);
        x /= 10;
      }

      vcs[num]++;
    }

    res = 0;
    FOR(i, 0, 1 << 10){
      if(vcs[i]) res += vcs[i]*(vcs[i] - 1)/2;
      FOR(j, i + 1, 1 << 10){
        if(i & j) res += vcs[i]*vcs[j];
      }
    }

    cout << res << "\n";
  }

  return 0;
}