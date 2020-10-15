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
  string ent;
  set<string> dict;
  
  while(cin >> ent)
    dict.insert(ent);
    
  forit(x, dict){
    FOR(i, 1, (*x).size()){
      if(dict.find((*x).substr(0, i)) != dict.end()){
        if(dict.find((*x).substr(i)) != dict.end()){
          cout << (*x) + "\n";
          break;
        }
      }
    }
  }
  
  return 0;
}