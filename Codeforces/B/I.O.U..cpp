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
  int n, m, a, b, d, sum = 0;
  cin >> n >> m;
  vector<int> debt(n + 1);
  
  FOR(i, 0, m){
    cin >> a >> b >> d;
    debt[a] -= d;
    debt[b] += d;
  }
  
  FOR(i, 1, n + 1) if(debt[i] < 0) sum -= debt[i];
  
  cout << sum << "\n";
  
  return 0;
}
