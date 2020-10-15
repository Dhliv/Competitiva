#include <bits/stdc++.h>
#define INF 2000000000
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
  int cases, mesas, k, posibles, aux;
  string ent;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> mesas >> k >> ent;
    vector<int> pos;
    posibles = 0;
    
    FOR(i, 0, ent.size())
      if(ent[i] == '1') pos.PB(i);
    
    if(pos.size()){
      
      if(pos[0] > k)
        posibles += (pos[0] + 1)/(k + 1);
      
      FOR(i, 1, pos.size()){
        aux = ((pos[i] - k) - (pos[i-1] + k)) + 1;
        if(aux > k){
          posibles += aux/(k+1);
        }
      }
      
      if((pos[pos.size() - 1] + k) < mesas)
        posibles += (mesas - (pos[pos.size() - 1] + k))/(k+1);
    }else{
      posibles++;
      posibles += (mesas - k)/(k+1);
    }
      
    cout << posibles << "\n";
  }

  return 0;
}