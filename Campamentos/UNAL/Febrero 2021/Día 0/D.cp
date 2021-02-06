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
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
 
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int cases;
  string a, b;
  bool able;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> a >> b;
    vector<int> p(26);
    
    FOR(i, 0, b.size()) p[b[i] - 'a']++;
    
    able = 0;
    FOR(i, 0, a.size()){
      if(p[a[i] - 'a'] != 0) p[a[i] - 'a']--;
      else{
        cout << i << "\n";
        able = true;
        break;
      }
    }
    
    if(!able) cout << a.size() << "\n";
  }
  
  return 0;
}