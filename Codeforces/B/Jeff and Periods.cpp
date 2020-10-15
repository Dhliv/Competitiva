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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;


int main(){
  int n, a, lim = 100001, c;
  cin >> n;
  vector<vector<int> > locs(lim);
  map<int, int> vecs;
  bool valid;
  
  FOR(i, 0, n){
    cin >> a;
    if(vecs.find(a) == vecs.end()) vecs.insert(MP(a, 1));
    else vecs[a]++;
    locs[a].PB(i);
  }
  
  vector<pair<int, int> > ans;
  
  forit(x, vecs){
    if(x->s == 1) ans.PB(MP(x->f, 0));
    else if(x->s == 2) ans.PB(MP(x->f, locs[x->f][1] - locs[x->f][0]));
    else{
      c = locs[x->f][1] - locs[x->f][0];
      valid = true;
      FOR(i, 2, x->s){
        if(c != locs[x->f][i] - locs[x->f][i - 1]) valid = false;
      }
      
      if(valid) ans.PB(MP(x->f, c));
    }
  }
  
  cout << ans.size() << "\n";
  
  FOR(i, 0, ans.size()) cout << ans[i].f << " " << ans[i].s << "\n";
  
  return 0;
}
