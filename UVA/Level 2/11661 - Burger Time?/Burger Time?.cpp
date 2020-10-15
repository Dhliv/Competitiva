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
  int L, best, d;
  bool R, D;
  string ent;
  
  while(cin >> L, L){
    cin >> ent;
    best = INF;
    R = D = false;
    
    FOR(i, 0, L){
      if(ent[i] != '.'){
        if(ent[i] == 'R'){
          if(D){
            if(i - d < best)
              best = i - d;
            D = false;
          }
          R = true;
        }else if(ent[i] == 'D'){
          if(R){
            if(i - d < best)
              best = i - d;
            R = false;
          }
          D = true;
        }else{
          best = 0;
          break;
        }
        d = i;
      }
    }
    
    cout << best << "\n";
  }
  
  return 0;
}