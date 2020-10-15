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
  int grup, total, regalado, cuantos;
  string name;
  bool primer = true;
  
  while(cin >> grup){
    if(!primer)
      cout << "\n";
    else
      primer = false;
    
    vector<string> orden(grup);
    map <string, int> diferencial;
    FOR(i, 0, grup){
      cin >> orden[i];
      diferencial.insert(MP(orden[i], 0));
    }
    
    FOR(i, 0, grup){
      cin >> name >> total >> cuantos;
      if(cuantos)
        regalado = total/cuantos;
      diferencial[name] -= regalado*cuantos;
      
      FOR(j, 0, cuantos){
        cin >> name;
        diferencial[name] += regalado;
      }
    }
    
    FOR(i, 0, grup)
      cout << orden[i] << " " << diferencial.find(orden[i])->second << "\n";
  }
  
  return 0;
}