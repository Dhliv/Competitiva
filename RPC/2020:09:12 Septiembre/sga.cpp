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
  int n, t, vecs;
  ll ans = 0;
  string ent;
  map<char, map<string, int> > cand;
  cin >> n;
  
  FOR(i, 0, n){
    cin >> ent;
    if(cand.find(ent[0]) == cand.end()){
      map<string, int> aux;
      aux.insert(MP(ent, 1));
      aux.insert(MP("a", 1));
      cand.insert(MP(ent[0], aux));
    }else{
      if((cand.find(ent[0])->s).find(ent) == (cand.find(ent[0])->s).end()){
        (cand.find(ent[0])->s).insert(MP(ent, 1));
        (cand.find(ent[0])->s)["a"]++;
      }else{
        (cand.find(ent[0])->s)[ent]++;
        (cand.find(ent[0])->s)["a"]++;
      }
    }
  }
  
  forit(x, cand){
    t = (x->s)["a"];
    forit(y, x->s){
      if(y->f == "a") continue;
      else{
        ans += (t - (y->s))*(y->s);
      }
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}