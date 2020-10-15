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
  int cases, mixto, m, f, pos;
  string ent, aux;
  cin >> cases;
  getline(cin, aux);
  
  FOR(i, 0, cases){
    getline(cin, ent);
    ent += " ";
    mixto = m = f = pos = 0;
    
    FOR(i, 0, ent.size()){
      if(isspace(ent[i])){
        aux = ent.substr(pos, i - pos);
        pos = i+1;
        
        if(aux[0] != aux[1])
          mixto++;
        else if(aux[0] == 'F')
          f++;
        else
          m++;
      }
    }
    
    if(m == f and ((m + f + mixto) > 1))
      cout << "LOOP\n";
    else
      cout << "NO LOOP\n";
  }
  
  return 0;
}