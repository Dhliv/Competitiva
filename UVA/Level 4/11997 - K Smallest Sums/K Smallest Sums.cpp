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
  int k, cont;
  pair<int, int> a;
  
  while(cin >> k){
    vector<vector<ll> > v(2, vector<ll> (k));
    FOR(i, 0, k) cin >> v[0][i];
    sort(v[0].begin(), v[0].end());
    
    FOR(i, 1, k){
      FOR(j, 0, k) cin >> v[1][j];
      sort(v[1].begin(), v[1].end());
      
      priority_queue<pair<int, int> > q;
      
      FOR(i, 0, k) q.push(MP(-(v[0][i] + v[1][0]), 0));
      
      FOR(i, 0, k){
        a = q.top();
        q.pop();
        
        v[0][i] = -a.f;
        
        if(a.s + 1 < k) q.push(MP(a.f + v[1][a.s] - v[1][a.s + 1], a.s + 1));
      }
    }
    
    FOR(i, 0, k - 1) cout << v[0][i] << " ";
    cout << v[0][k - 1] << "\n";
  }
  
  return 0;
}
