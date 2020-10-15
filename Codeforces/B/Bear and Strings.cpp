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
  int n, in, jn, v;
  ll sum = 0;
  string ent, b = "bear";
  cin >> ent;
  n = ent.size();
  vector<pair<int, int> > p;
  bool is;
  
  FOR(i, 0, n - 3){
    if(ent[i] == b[0]){
      is = true;
      FOR(j, 1, 4){
        if(ent[i + j] != b[j]){
          is = false;
          i += j - 1;
          break;
        }
      }
      
      if(is){
        p.PB(MP(i, i + 3));
        i += 3;
      }
    }
  }
  
  if(p.size()){
    in = p[0].f;
    sum += in*(n - p[0].s);
    
    FOR(i, 0, p.size() - 1){
      sum += n - p[i].s;
      v = p[i + 1].f - (in + 1);
      in = p[i + 1].f;
      
      sum += v*(n - p[i + 1].s);
    }
    
    sum += n - p[p.size() - 1].s;
  }
  
  cout << sum << "\n";
  
  return 0;
}
