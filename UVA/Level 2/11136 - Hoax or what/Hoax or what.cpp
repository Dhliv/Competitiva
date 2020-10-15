#include <bits/stdc++.h>
#define LINF LLONG_MAX
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
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int days, k, x, y;
  ll cost;
  
  while(cin >> days, days){
    map<int, int> bills;
    cost = 0;
    
    FOR(i, 0, days){
      cin >> k;
      FOR(j, 0, k){
        cin >> x;
        if(bills.find(x) == bills.end()) bills.insert(MP(x, 1));
        else bills[x]++;
      }
      
      x = bills.begin()->f, y = (--bills.end())->f;
      if(bills[x] > 1) bills[x]--;
      else bills.erase(x);
      
      if(bills[y] > 1) bills[y]--;
      else bills.erase(y);
      
      cost += y - x;
    }
    
    cout << cost << "\n";
  }
  
  return 0;
}