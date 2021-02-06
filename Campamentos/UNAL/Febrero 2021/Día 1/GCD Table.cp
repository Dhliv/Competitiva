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
  int n, y, x;
  cin >> n;
  
  deque<int> ans;
  priority_queue<int> p;
  map<int, int> m;
  FOR(i, 0, n){
    FOR(j, 0, n){
      cin >> x;
      p.push(x);
      if(m.find(x) == m.end()) m.insert(MP(x, 1));
      else m[x]++;
    }
  }
  
  while(!p.empty()){
    x = p.top();
    p.pop();
    
    if(m.find(x) == m.end()) continue;
    
    FOR(i, 0, ans.size()){
      y = __gcd(x, ans[i]);
      m[y] -= 2;
      if(m[y] == 0) m.erase(y);
    }
    
    m[x]--;
    if(m[x] == 0) m.erase(x);
    ans.PB(x);
  }
  
  cout << ans[0];
  FOR(i, 1, ans.size()) cout << " " << ans[i];
  cout << "\n";
  
  return 0;
}