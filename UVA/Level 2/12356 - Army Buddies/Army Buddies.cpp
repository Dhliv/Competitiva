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
  int S, B, a, b, l, r, pos;
  map<int, int> soldiers;
  
  FOR(i, 1, 100002)
    soldiers.insert(MP(i, i));
  
  while(cin >> S >> B, S+B){
    map<int, int> aux;
    aux.insert(soldiers.begin(), soldiers.find(S+1));
    
    FOR(i, 0, B){
      cin >> a >> b;
      
      if(aux.find(a) == aux.begin())
        l = 0;
      else
        l = (--aux.find(a))->first;
        
      if(aux.find(b) == (--aux.end()))
        r = 0;
      else  
        r = (++aux.find(b))->first;
      
      FOR(eli, a, b+1)
        aux.erase(eli);
      
      if(l)
        cout << l << " ";
      else
        cout << "* ";
      
      if(r)
        cout << r << "\n";
      else
        cout << "*\n";
    }
    cout << "-\n";
  }
  
  return 0;
}