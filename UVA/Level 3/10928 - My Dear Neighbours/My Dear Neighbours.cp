#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
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
  int cases, n, d, cont, mini;
  cin >> cases;
  string ent;
  
  FOR(ab, 0, cases){
    cin >> n;
    getline(cin, ent);
    deque<int> ans;
    vector<int> p(n);
    
    mini = INF;
    FOR(i, 0, n){
      getline(cin, ent);
      cont = 0;
      ent += " ";
      
      FOR(j, 0, ent.size()) if(isspace(ent[j])) cont++;
      
      mini = min(mini, cont);
      p[i] = cont;
    }
    
    FOR(i, 0, n) if(p[i] == mini) ans.PB(i + 1);
    
    cout << ans[0];
    FOR(i, 1, ans.size()) cout << " " << ans[i];
    cout << "\n";
  }
  
  return 0;
}