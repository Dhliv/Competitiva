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

int main(){
  int cases, ans, n, pos, big, cont;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    big = cont = 0;
    vector<int> dat(n);
    deque<pair<int, int> > q; // inicio, final
    pair<int, int> x, y;
    
    FOR(i, 0, n) cin >> dat[i];
    
    FOR(i, 0, n){
      if(dat[i] == 1){
        cont++;
      }else{
        if(cont != 0){
          q.PB(MP(i - cont, i - 1));
          cont = 0;
        }
      }
      if(i + 1 == n and cont != 0){
        if(cont != 0){
          q.PB(MP(i + 1 - cont, i));
          cont = 0;
        }
      }
    }
    
    ans = 0;
    while(q.size() > 1){
      x = q.F(); q.P_F();
      y = q.F(); q.P_F();
      
      ans += (y.f - (x.s + 1));
      q.PF(y);
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}