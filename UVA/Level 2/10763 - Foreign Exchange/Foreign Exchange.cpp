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
  int n, a, b;
  
  while(cin >> n, n){
    map<pair<int, int>, int> van;
    pair<int, int> der, rder;
    
    FOR(i, 0, n){
      cin >> a >> b;
      der = MP(a, b);
      rder = MP(b, a);
      if(van.find(rder) != van.end()){
        if(van.find(rder)->second == 1)
          van.erase(rder);
        else
          van[rder]--;
      }else{
        if(van.find(der) == van.end())
          van[der] = 1;
        else
          van[der]++;
      }
    }
    
    if(van.size())
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  
  return 0;
}