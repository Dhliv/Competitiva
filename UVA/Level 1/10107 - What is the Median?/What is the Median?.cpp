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
  int ent;
  vector<int> v;
  
  while(cin >> ent){
    v.PB(ent);
    sort(v.begin(), v.end());
    
    if(v.size()%2)
      cout << v[v.size()/2] << "\n";
    else
      cout << (v[v.size()/2 - 1] + v[v.size()/2])/2 << "\n";
  }

  return 0;
}