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
  int cases;
  string ent;
  bool valid;
  cin >> cases;
  getline(cin, ent);
  
  FOR(a, 0, cases){
    getline(cin, ent);
    valid = true;
    vector<int> pila; //1 -> [, 0 -> (.
    
    if(ent.size()){
      FOR(i, 0, ent.size()){
        if(ent[i] == '(')
          pila.PB(0);
        else if(ent[i] == '[')
          pila.PB(1);
        else if(ent[i] == ']'){
          if(pila.size() and pila.B() == 1)
            pila.P_B();
          else{
            valid = false;
            break;
          }
        }else if(ent[i] == ')'){
          if(pila.size() and pila.B() == 0)
            pila.P_B();
          else{
            valid = false;
            break;
          }
        }
      }
      
      if(valid and pila.size() == 0)
        cout << "Yes\n";
      else
        cout << "No\n";
    }else
      cout << "Yes\n";
  }
  
  return 0;
}