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
  int cases, n;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    vector<int> v(n);
    
    FOR(i, 0, n)
      cin >> v[i];
      
    FOR(i, 1, v.size() - 1){
      if(v[i] >= v[i-1] and v[i] <= v[i+1]){
        v.erase(v.begin() + i);
        i--;
      }else if(v[i] <= v[i-1] and v[i] >= v[i+1]){
        v.erase(v.begin() + i);
        i--;
      }
    }
    
    cout << v.size() << "\n";
    
    FOR(i, 0, v.size() - 1)
      cout << v[i] << " ";
      
    cout << v[v.size() - 1] << "\n";
  }
  
  return 0;
}