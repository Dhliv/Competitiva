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
#define dat pair<int, pair<int, int> >
#define MAX 201

using namespace std;

int main(){
  int t, x, y, w, z, dest;
  ll acum;
  dat ax, bx;
  vector<int> d(3), c(3);
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> c[0] >> c[1] >> c[2] >> dest;
    vector<vector<vector<bool> > > vi(c[0] + 1, vector<vector<bool> > (c[1] + 1, vector<bool> (c[2] + 1)));
    vector<ll> s(MAX, INF);
    priority_queue<pair<int, dat> > q;
    q.push(MP(0, MP(0, MP(0, c[2]))));
    
    while(!q.empty()){
      ax = q.top().s;
      acum = -q.top().f;
      q.pop();
      
      d[0] = ax.f, d[1] = ax.s.f, d[2] = ax.s.s;
      if(vi[d[0]][d[1]][d[2]]) continue;
      vi[d[0]][d[1]][d[2]] = 1;
      
      FOR(i, 0, 3) s[d[i]] = min(acum, s[d[i]]);
      
      FOR(i, 0, 3){
        if(d[i] == 0) continue;
        
        FOR(j, 0, 3){
          if(i == j) continue;
          x = c[j] - d[j];
          w = min(x, d[i]);
          y = d[i] - w;
          z = d[j] + w;
          
          if(i + j == 1) bx = (i == 0) ? MP(y, MP(z, d[2])) : MP(z, MP(y, d[2]));
          else if(i + j == 2) bx = (i == 0) ? MP(y, MP(d[1], z)) : MP(z, MP(d[1], y));
          else bx = (i == 1) ? MP(d[0], MP(y, z)) : MP(d[0], MP(z, y));
          
          q.push(MP(-(acum + w), bx));
        }
      }
    }
    
    if(s[dest] != INF) cout << s[dest] << " ";
    else{
      FORI(i, dest - 1, 0){
        if(s[i] != INF){
          cout << s[i] << " ";
          dest = i;
          break;
        }
      }
    }
    cout << dest << "\n";
  }
  
  return 0;
}