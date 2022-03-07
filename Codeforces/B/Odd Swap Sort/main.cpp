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

  int t, n, pb, ib, x; cin >> t;
  bool able;

  FOR(ab, 0, t){
  	cin >> n;
  	pb = ib = -1;
  	able = true;

  	FOR(i, 0, n){
  		cin >> x;

  		if(x & 1){
  			if(ib  > x) able = false;
  			ib = x;
  		}else{
  			if(pb > x) able = false;
  			pb = x;
  		}
  	}

  	if(able) cout << "yes\n";
  	else cout << "no\n";
  }

  return 0;
}