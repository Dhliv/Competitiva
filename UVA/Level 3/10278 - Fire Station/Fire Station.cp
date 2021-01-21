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

int n;

void distra(deque<int> &src, vector<int> &s, vector<vector<pair<int, int> > > &grf){
  int x, y, c;
  vector<bool> v(n + 1);
  priority_queue<pair<int, int> > p;
  FOR(i, 0, src.size()){
    s[src[i]] = 0;
    p.push(MP(0, src[i]));
  }
  
  while(!p.empty()){
    x = p.top().s;
    p.pop();
    
    if(v[x]) continue;
    v[x] = 1;
    
    FOR(i, 0, grf[x].size()){
      y = grf[x][i].f;
      if(v[y]) continue;
      c = grf[x][i].s + s[x];
      
      if(s[y] > c){
        s[y] = c;
        p.push(MP(-c, y));
      }
    }
  }
  
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  int t, f, ans, maxi, x, y, c, pos, mini;
  string ent;
  vector<int> d(3);
  cin >> t;
  
  FOR(ab, 0, t){
    if(ab) cout << "\n";
    cin >> f >> n;
    deque<int> src(f);
    vector<vector<pair<int, int> > > grf(n + 1);
    vector<bool> v(n + 1);
    
    FOR(i, 0, f){
      cin >> src[i];
      v[src[i]] = 1;
    }
    
    getline(cin, ent);
    while(getline(cin, ent)){
      if(ent.size() == 0) break;
      ent += " ";
      c = pos = 0;
      FOR(i, 0, ent.size()){
        if(isspace(ent[i])){
          d[c++] = stoi(ent.substr(pos, i - pos));
          pos = i + 1;
        }
      }
      
      grf[d[0]].PB(MP(d[1], d[2]));
      grf[d[1]].PB(MP(d[0], d[2]));
    }
    
    mini = INF;
    ans = 1;
    FOR(i, 1, n + 1){
      if(v[i]) continue;
      vector<int> s(n + 1, INF);
      src.PB(i);
      distra(src, s, grf);
      maxi = 0;
      
      FOR(j, 1, n + 1) maxi = max(maxi, s[j]);
      if(mini > maxi){
        mini = maxi;
        ans = i;
      }
      src.P_B();
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}