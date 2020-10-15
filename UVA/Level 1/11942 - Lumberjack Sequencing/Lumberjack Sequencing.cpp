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
  int cases, aux;
  cin >> cases;
  cout << "Lumberjacks:\n";
  
  FOR(n, 0, cases){
    vector<int> ent(10), asc, desc;
    FOR(i, 0, 10)
      cin >> ent[i];
    asc = ent;
    sort(asc.begin(), asc.end());
    desc = asc;
    reverse(desc.begin(), desc.end());
    
    if(ent == asc or ent == desc)
      cout << "Ordered\n";
    else
      cout << "Unordered\n";
  }
  
  return 0;
}