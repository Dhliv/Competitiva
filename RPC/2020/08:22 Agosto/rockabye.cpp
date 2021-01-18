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
  int cases, n, k, f, pos;
  string ent;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n >> k;
    vector<pair<string, int> > med(n);
    priority_queue<pair<int, int> > p;
    map<string, int> orden;
    
    FOR(i, 0, n){
      cin >> ent >> f;
      med[i] = MP(ent, f);
      orden.insert(MP(ent, i));
      p.push(MP(-f, -i));
    }
    
    FOR(i, 0, k){
      pos = -p.top().s;
      cout << -p.top().f << " " << med[pos].f << "\n";
      p.push(MP(p.top().f - med[pos].s, -pos));
      p.pop();
    }
  }
  
  return 0;
}
