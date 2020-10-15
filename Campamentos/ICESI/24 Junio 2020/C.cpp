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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int n, aux;
  cin >> n;
  vector<vector<ll> > maxi(n), data(n);
  
  FOR(i, 0, n){
    FOR(j, 0, 3){
      cin >> aux;
      data[i].PB(aux);
      maxi[i].PB(MINF);
    }
  }
  
  FOR(i, 0, 3)
    maxi[0][i] = data[0][i];
    
  FOR(i, 1, n){
    maxi[i][0] = data[i][0] + max(maxi[i-1][1], maxi[i-1][2]);
    maxi[i][1] = data[i][1] + max(maxi[i-1][0], maxi[i-1][2]);
    maxi[i][2] = data[i][2] + max(maxi[i-1][0], maxi[i-1][1]);
  }
  
  cout << max(maxi[n-1][0], max(maxi[n-1][1], maxi[n-1][2])) << "\n";
  
  return 0;
}