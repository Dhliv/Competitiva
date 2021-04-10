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
  int n, t, p, act, x;
  bool all = true;
  cin >> n >> p;
  deque<int> q;
  
  FOR(i, 0, n){
    cin >> x;
    q.PF(x);
    if(x != 0) all = false;
  }
  
  act = (q[0] == 0) ? 0 : 1;
  vector<int> sol(n);
  sol[0] = act;
  
  FOR(i, 1, n){
    if(q[i] > q[i - 1]) act++;
    sol[i] = act;
  }
  
  if(act != p and !all) cout << "ambiguous\n";
  else{
    x = n - 1;
    FORI(i, x, 0) cout << sol[i] << "\n";
  }

  return 0;
}