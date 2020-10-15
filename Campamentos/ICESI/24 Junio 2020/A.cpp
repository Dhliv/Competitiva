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
  ll N;
  cin >> N;
  vector<ll> alts(N), mins(N, INF);
  
  FOR(i, 0, N)
    cin >> alts[i];
    
  mins[0] = 0;
  mins[1] = abs(alts[1] - alts[0]);
  
  FOR(i, 2, N)
    mins[i] = min(mins[i-1] + abs(alts[i-1] - alts[i]), mins[i-2] + abs(alts[i-2] - alts[i]));
  
  cout << mins[N-1] << "\n";
  
  return 0;
}