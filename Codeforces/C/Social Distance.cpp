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
  int cases, mesas, k, disp, ceros;
  string ent;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> mesas >> k;
    cin >> ent;
    vector<int> posU;
    disp = 0;
    
    FOR(i, 0, mesas){
      if(ent[i] == '1')
        posU.PB(i);
    }
    
    //desde 0 hasta el primer 1:
    
    if(posU.size()){
      ceros = posU[0] - k;
      if(ceros > 0){
        disp += ceros/(k+1);
        if(ceros%(k+1)) disp++;
      }
      
      //intermedios:
      
      FOR(i, 1, posU.size()){
        ceros = posU[i] - posU[i-1] - 1 - 2*k;
        if(ceros > 0){
          disp += ceros/(k+1);
          if(ceros%(k+1)) disp++;
        }
      }
      
      //desde el ultimo uno hasta el ultimo cero:
      
      ceros = mesas - posU[posU.size() - 1] - 1 - k;
      if(ceros > 0){
        disp += ceros/(k+1);
        if(ceros%(k+1)) disp++;
      }
    }else{
      disp += mesas/(k+1);
      if(mesas%(k+1)) disp++;
    }
    cout << disp << "\n";
  }
  
  return 0;
}