#include <bits/stdc++.h>
#define INF 1000000000
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
  string entrada, aux;
  int i, j, querys, conta = 1;
  bool discrepa;
  
  while(cin >> entrada){
    cin >> querys;
    
    cout << "Case " << conta++ << ":\n";
    
    FOR(a, 0, querys){
      cin >> i >> j;
      discrepa = false;
      
      FOR(b, min(i, j)+1, max(i, j)+1){
        if(entrada[b] != entrada[b-1]){
          discrepa = true;
          break;
        }
      }
      
      if(!discrepa)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  
  return 0;
}