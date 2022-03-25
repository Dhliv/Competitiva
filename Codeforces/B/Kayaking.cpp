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
 
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int _n, n; cin >> _n;
  n = _n*2;
  vector<int> p(n);
  FOR(i, 0, n) cin >> p[i];

  sort(p.begin(), p.end());

  int ans = INF, sum = 0, last;
  FOR(i, 0, n - 1){
  	FOR(j, i + 1, n){
  		last = -1;
  		sum = 0;
  		for(int k = 0; k < n; k++){
  			if(k == i or k == j) continue;
  			if(last != -1){
  				sum += (p[k] - p[last]);
  				last = -1;
  			}else last = k;
  		}

  		ans = min(ans, sum);
  	}
  }

  cout << ans << "\n";

  return 0;
}
