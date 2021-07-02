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
#define MAX 512

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m, maxi, c, a, x, k, mini;
  pair<int, int> ans;
  cin >> n >> m;
  
  vector<int> ex(MAX), cost(MAX, INF), costC(MAX, INF), people(MAX), dos(MAX), id(MAX);
  vector<priority_queue<pair<int, int> > > cDl(MAX);
  vector<pair<int, int> > par(MAX);
  
  FOR(i, 0, n){
    cin >> k;
    x = 0;
    FOR(j, 0, k){
      cin >> a;
      a--;
      x |= 1 << a;
    }
    
    people[x]++;
  }
  
  FOR(i, 0, m){
    cin >> c >> k;
    x = 0;
    FOR(j, 0, k){
      cin >> a;
      a--;
      x |= 1 << a;
    }
    
    ex[x] = 1;
    if(c < cost[x]){
      cost[x] = c;
      id[x] = i;
    }
    
    cDl[x].push(MP(c, i));
    if(cDl[x].size() > 2) cDl[x].pop();
  }
  
  FOR(i, 0, MAX){
    if(!ex[i]) continue;
    FOR(j, i + 1, MAX){
      if(!ex[j]) continue;
      x = i | j;
      c = cost[i] + cost[j];
      dos[x] = 1;
      if(c < costC[x]){
        costC[x] = c;
        par[x] = MP(id[i], id[j]);
      }
    }
    
    if(cDl[i].size() == 2){
      dos[i] = 1;
      c = cDl[i].top().f;
      a = cDl[i].top().s;
      cDl[i].pop();
      c += cDl[i].top().f;
      
      if(c < costC[i]){
        costC[i] = c;
        par[i] = MP(a, cDl[i].top().s);
      }
    }
  }
  
  maxi = 0;
  mini = INF;
  FOR(i, 0, MAX){
    if(!dos[i]) continue;
    k = 0;
    
    FOR(j, 0, MAX){
      if(!people[j]) continue;
      if((i | j) == i) k += people[j];
    }
    
    if(k > maxi){
      maxi = k;
      mini = costC[i];
      ans = par[i];
    }else if(k == maxi and costC[i] < mini){
      mini = costC[i];
      ans = par[i];
    }
  }
  
  cout << ans.f + 1 << " " << ans.s + 1 << "\n";
  
  return 0;
}