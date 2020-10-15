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
  int ori, dest, k, x, y, lim = 9999, cont, cas = 1;
  
  while(cin >> ori >> dest >> k, k + ori + dest){
    cout << "Case " << cas++ << ": ";
    
    vector<bool> seen(lim + 1, 0);
    vector<int> sums(k);
    
    FOR(i, 0, k) cin >> sums[i];
    
    deque<int> q, next;
    q.PB(ori);
    
    if(ori != dest){
      cont = 0;
      while(true){
        
        while(!q.empty()){
          x = q.F();
          q.P_F();
          
          if(seen[x]) continue;
          seen[x] = true;
          
          FOR(i, 0, k){
            y = (x + sums[i])%(lim + 1);
            if(!seen[y]) next.PB(y);
          }
        }
        if(seen[dest]){
          cout << cont << "\n";
          break;
        }
        
        if(next.empty()){
          cout << "Permanently Locked\n";
          break;
        }
        
        q.swap(next);
        cont++;
      }
    }else cout << 0 << "\n";
  }
  
  return 0;
}