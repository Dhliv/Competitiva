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
  int n, k;
  ll sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  
  FOR(i, 0, n) cin >> v[i];
  
  sort(v.begin(), v.end());
  
  FOR(i, 0, k){
    if(i < n and v[i] <= 0){
      v[i] *= -1;
    }else{
      if(i >= n) i--, k--;
      if(i > 0){
        if(v[i] > v[i - 1]) v[i - 1] *= -1;
        else v[i] *= -1;
      }else v[i] *= -1;
      i--, k--;
    }
  }
  
  FOR(i, 0, n) sum += v[i];
  
  cout << sum << "\n";
  
  return 0;
}
