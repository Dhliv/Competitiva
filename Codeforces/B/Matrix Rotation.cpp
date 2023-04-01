#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846

using namespace std;
 
const ld EPSILON = 0.0000001;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  vector<vector<int> > p(2, vector<int>(2)), cp;

  while(t--){
  	FOR(i, 0, 2){
  		FOR(j, 0, 2) cin >> p[i][j];
  	}

  	bool able = false;
  	cp = p;
  	FOR(i, 0, 4){
  		p = cp;
  		able |= cp[0][0] < cp[0][1] and cp[1][0] < cp[1][1] and cp[0][0] < cp[1][0] and cp[0][1] < cp[1][1];
  		cp[0][0] = p[1][0];
  		cp[0][1] = p[0][0];
  		cp[1][0] = p[1][1];
  		cp[1][1] = p[0][1];
  	}

  	cout << (able ? "YES" : "NO") << "\n";
  }

  return 0;
}