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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int t;

int look(int ori, int dest){
  int izq, der;
  if(ori == dest) return 0;
  else if(ori > dest){
    der = ori - dest;
    izq = dest + (t - ori);
  }else{
    der = dest - ori;
    izq = ori + (t - dest);
  }
  
  return min(izq, der);
}

int main(){
  int n, k, dat;
  ll mini;
  deque<ll> mins, next, bef, minsN;
  mins.PB(0);
  bef.PB(0);
  cin >> t >> n;
  
  FOR(i, 0, n){
    cin >> k;
    FOR(j, 0, k){
      cin >> dat;
      mini = LLONG_MAX;
      next.PB(dat);
      
      FOR(a, 0, bef.size()) mini = min(mini, mins[a] + look(dat, bef[a]%t + 1));
      minsN.PB(mini);
    }
    mins.swap(minsN);
    bef.swap(next);
    next.clear();
    minsN.clear();
  }
  
  mini = LONG_MAX;
  FOR(i, 0, mins.size()) mini = min(mini, mins[i]);
  
  cout << mini << "\n";
  
  return 0;
}