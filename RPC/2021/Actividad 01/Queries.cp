#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF -1000000000
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
  int cases, m, e, c;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> m;
    deque<int> q;
    map<int, int> s;
    
    FOR(i, 0, m){
      cin >> e;
      if(e == 1){
        cin >> c;
        q.PF(c);
        if(s.find(c) == s.end()) s.insert(MP(c, 1));
        else s[c]++;
      }else if(e == 2 and q.size()){
        c = q.F();
        q.P_F();
        s[c]--;
        if(s[c] == 0) s.erase(c);
      }else if(e == 3){
        if(q.empty()) cout << "Empty!\n";
        else cout << abs(s.begin()->f - (--(s.end()))->f) << "\n";
      }
    }
  }
  
  return 0;
}