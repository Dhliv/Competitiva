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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int n, q, ent, best = MINF, it = -1, pos, op = 1, pri, sec, con = INF;
  ll quer;
  cin >> n >> q;
  deque<int> dq;
  vector<pair<ll, int> > querys(q);
  vector<pair<int, int> > ans(q);
  
  FOR(i, 0, n){
    cin >> ent;
    if(ent > best)
      best = ent, it = i+1;
    dq.PB(ent);
  }
  
  FOR(i, 0, q){
    cin >> quer;
    querys[i] = MP(quer, i);
  }
    
  sort(querys.begin(), querys.end());
  
  FOR(i, 0, q){
    quer = querys[i].first;
    if(quer < it){
      FOR(j, 0, quer - op){
        pri = dq[0], sec = dq[1];
        dq.P_F();
        dq.P_F();
        
        if(pri > sec)
          dq.PB(sec), dq.PF(pri);
        else
          dq.PB(pri), dq.PF(sec);
      }
      op += quer - op;
      ans[querys[i].second] = MP(dq[0], dq[1]);
    }else{
      con = i;
      break;
    }
  }
  
  FOR(i, 0, it - op){
    pri = dq[0], sec = dq[1];
    dq.P_F();
    dq.P_F();
        
    if(pri > sec)
      dq.PB(sec), dq.PF(pri);
    else
      dq.PB(pri), dq.PF(sec);
  }
  
  FOR(i, con, q)
    ans[querys[i].second] = MP(best, dq[(querys[i].first - it)%(n - 1) + 1]);
    
  FOR(i, 0, q)
    cout << ans[i].first << " " << ans[i].second << "\n";
  
  return 0;
}