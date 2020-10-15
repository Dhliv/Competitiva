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

int main() {
  int fil, col, val, bef, ans;
  while(cin >> fil, fil){
    cin >> col;
    priority_queue<pair<int, int> > pq;
    cin >> val;
    pq.push(MP(-val, 0));
    set<int> pos;
    pos.insert(0);
    vector<int> alts(col);
    alts[0] = val;
    
    FOR(i, 1, col){
      cin >> bef;
      if(bef != val){
        pq.push(MP(-bef, i));
        pos.insert(i);
        alts[i] = bef;
        val = bef;
      }
    }
    
    ans = 0;
    pair<int, int> act;
    
    while(pq.size() != 1){
      act = pq.top();
      pq.pop();
      
      if(pos.find(act.s) != pos.begin() and pos.find(act.s) != (--pos.end())){
        val = min(alts[*(--pos.find(act.s))], alts[*(++pos.find(act.s))]);
        if(val != act.f)
          ans += val + act.f;
      }
      else if(pos.find(act.s) == pos.begin()){
        val = alts[*(++pos.find(act.s))];
        if(val != -act.f)
          ans += val + act.f;
      }
      else{
        val = alts[*(--pos.find(act.s))];
        if(val != act.f)
          ans += val + act.f;
      }
      
      pos.erase(act.s);
    }
    
    act = pq.top();
    
    ans += fil - alts[*pos.find(act.s)];
    cout << ans << "\n";
  }

	return 0;
}