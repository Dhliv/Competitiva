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

int Y, P, best, a, b;

void solve(vector<int> v, int pos){
  int low = pos, high = P-1, mid;
  
  while(low <= high){
    mid = (low + high)/2;
    if((v[pos] + Y - 1) < v[mid]) high = mid - 1;
    else low = mid + 1;
  }
  
  if(best < (low - pos)){
    best = low - pos;
    a = pos;
    b = low - 1;
  }
}

int main(){
  while(cin >> Y >> P){
    vector<int> v(P);
    
    FOR(i, 0, P)
      cin >> v[i];
    
    if(v.size() > 1){
      best = MINF;
      
      FOR(i, 0, P-1)
        solve(v, i);
        
      cout << best << " " << v[a] << " " << v[b] << "\n";
    }else
      cout << v.size() << "\n";
  }
  
  return 0;
}