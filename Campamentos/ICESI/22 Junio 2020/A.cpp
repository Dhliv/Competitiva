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
  map<int, int> leMape;
  int ent, aux;
  
  cin >> ent;
  
  FOR(i, 0, ent){
    cin >> aux;
    leMape[aux] = 0;
  }
  
  if(leMape.size() > 1)
    cout << (++leMape.begin())->first << "\n";
  else
    cout << "NO\n";
  
  return 0;
}