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
  ll mini = INF, maxi = MINF, h;
  int n;
  cin >> n;
  vector<int> a(3), b(3), ax, bx, orden{0, 1, 2, 3, 4, 5};
  
  FOR(i, 0, 3) cin >> a[i];
  FOR(i, 0, 3) cin >> b[i];
  
  do{
    ax = a;
    bx = b;
    FOR(i, 0, 6){
      if(orden[i] == 0){
        if(ax[0] > bx[0]){
          ax[0] = ax[0] - bx[0];
          bx[0] = 0;
        }else{
          bx[0] = bx[0] - ax[0];
          ax[0] = 0;
        }
      }else if(orden[i] == 1){
        if(ax[0] > bx[2]){
          ax[0] = ax[0] - bx[2];
          bx[2] = 0;
        }else{
          bx[2] = bx[2] - ax[0];
          ax[0] = 0;
        }
      }else if(orden[i] == 2){
        if(ax[1] > bx[1]){
          ax[1] = ax[1] - bx[1];
          bx[1] = 0;
        }else{
          bx[1] = bx[1] - ax[1];
          ax[1] = 0;
        }
      }else if(orden[i] == 3){
        if(ax[1] > bx[0]){
          ax[1] = ax[1] - bx[0];
          bx[0] = 0;
        }else{
          bx[0] = bx[0] - ax[1];
          ax[1] = 0;
        }
      }else if(orden[i] == 4){
        if(ax[2] > bx[2]){
          ax[2] = ax[2] - bx[2];
          bx[2] = 0;
        }else{
          bx[2] = bx[2] - ax[2];
          ax[2] = 0;
        }
      }else{
        if(ax[2] > bx[1]){
          ax[2] = ax[2] - bx[1];
          bx[1] = 0;
        }else{
          bx[1] = bx[1] - ax[2];
          ax[2] = 0;
        }
      }
    }
    
    h = *(max_element(ax.begin(), ax.end()));
    mini = min(mini, h);
  }while(next_permutation(orden.begin(), orden.end()));
  
cout << mini << " " << (min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0])) << "\n";
  
  return 0;
}