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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main() {
  int n, quers, l, r, gana;
  cin >> n >> quers;
  
  vector<int> defeat(n+1);
  set<int> alive;
  set<int>::iterator it;
  deque<int> dq;
  
  FOR(i, 1, n+1)
    alive.insert(i);
  
  FOR(i, 0, quers){
    cin >> l >> r >> gana;
    it = alive.lower_bound(l);
    
    while(it != alive.end()){
      if((*it) <= r){
        if(gana != (*it)){
          dq.PB((*it));
          defeat[(*it)] = gana;
        }
        ++it;
      }else
        break;
    }
    
    while(!dq.empty()){
      alive.erase(dq.F());
      dq.P_F();
    }
  }
  
  FOR(i, 1, n+1)
    cout << defeat[i] << " ";
  
  return 0;
}