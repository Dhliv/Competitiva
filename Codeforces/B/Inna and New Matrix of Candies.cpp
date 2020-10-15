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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int n, m, a, b, ans = 0;
  bool poss = true;
  cin >> n >> m;
  
  vector<string> v(n);
  vector<pair<int, int> > pos(n);
  set<int> moves;
  
  FOR(i, 0, n)
    cin >> v[i];
    
  FOR(i, 0, n){
    FOR(j, 0, m){
      if(v[i][j] == 'G')
        a = j;
      else if(v[i][j] == 'S')
        b = j;
    }
    pos[i] = MP(a, b);
  }
  
  FOR(i, 0, n){
    if(pos[i].f > pos[i].s)
      poss = false;
    else if(pos[i].f < pos[i].s)
      moves.insert(min(pos[i].s - pos[i].f, m - (1 + pos[i].f)));
  }
  
  if(poss){
    ans = 1;
    a = *moves.begin();
    
    while(moves.upper_bound(a) != moves.end()){
      ans++;
      a = *(moves.upper_bound(a));
    }
    
    cout << ans << "\n";
  }
  else
    cout << "-1\n";
  
  return 0;
}