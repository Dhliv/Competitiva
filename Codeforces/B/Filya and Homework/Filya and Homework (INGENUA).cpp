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

int main(){
  int val, ele, med, a1, a2, x;
  cin >> ele;
  bool pos = true, p1, p2;
  
  map<int, int> v;
  vector<int> dat;
  
  FOR(i, 0, ele){
    cin >> val;
    v[val] = 0;
  }
  
  forit(x, v)
    dat.PB(x->first);
  
  if(dat.size()%2){
    med = dat[dat.size()/2];
    x = abs(med - dat[0]);
    FOR(i, 1, dat.size()){
      if(abs(x - dat[i]) != med and med != dat[i] and x + dat[i] != med){
        pos = false;
        break;
      }
    }
    
    if(pos)
      cout << "YES\n";
    else
      cout << "NO\n";
  }else{
    a1 = dat[dat.size()/2];
    a2 = dat[dat.size()/2 - 1];
    p1 = p2 = true;
    
    x = abs(a1 - dat[0]);
    FOR(i, 1, dat.size()){
      if(abs(x - dat[i]) != a1 and a1 != dat[i] and x + dat[i] != a1){
        p1 = false;
        break;
      }
    }
    
    x = abs(a2 - dat[0]);
    FOR(i, 1, dat.size()){
      if(abs(x - dat[i]) != a2 and a2 != dat[i] and x + dat[i] != a2){
        p2 = false;
        break;
      }
    }
    
    if(p1 or p2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  
  return 0;
}