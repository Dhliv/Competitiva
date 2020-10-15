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
  int cases, klings, w, h, valx;
  char k;
  cin >> cases;

  FOR(a, 0, cases){
    cin >> klings >> w >> h;
    pair<int, int> ori;
    pair<int, pair<int, int> > nodo;
    vector<string> table(h);
    vector<int> vals(26);
    vector<vector<int> > adya(h, vector<int> (w));
    
    FOR(i, 0, klings){
      cin >> k >> valx;
      vals[k - 'A'] = valx;
    }
    
    FOR(i, 0, h)
      cin >> table[i];
    
    FOR(i, 0, h){
      FOR(j, 0, w){
        adya[i][j] = vals[table[i][j] - 'A'];
        if(table[i][j] == 'E'){
          ori = MP(i, j);
          adya[i][j] = 0;
        }
      }
    }
    
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(MP(0, ori));
    vector<vector<bool> > visit(h, vector<bool> (w));
    
    while(!pq.empty()){
      nodo = pq.top();
      pq.pop();
      
      if(visit[nodo.s.f][nodo.s.s]) continue;
      visit[nodo.s.f][nodo.s.s] = true;
      
      if(0 == nodo.s.f or h - 1 == nodo.s.f or 0 == nodo.s.s or w - 1 == nodo.s.s){
        cout << -nodo.f << "\n";
        break;
      }
      
      if(nodo.s.f + 1 < h and !visit[nodo.s.f + 1][nodo.s.s])
        pq.push(MP(nodo.f - adya[nodo.s.f + 1][nodo.s.s], MP(nodo.s.f + 1, nodo.s.s)));
        
      if(nodo.s.f - 1 >= 0 and !visit[nodo.s.f - 1][nodo.s.s])
        pq.push(MP(nodo.f - adya[nodo.s.f - 1][nodo.s.s], MP(nodo.s.f - 1, nodo.s.s)));
        
      if(nodo.s.s + 1 < w and !visit[nodo.s.f][nodo.s.s + 1])
        pq.push(MP(nodo.f - adya[nodo.s.f][nodo.s.s + 1], MP(nodo.s.f, nodo.s.s + 1)));
        
      if(nodo.s.s - 1 >= 0 and !visit[nodo.s.f][nodo.s.s - 1])
        pq.push(MP(nodo.f - adya[nodo.s.f][nodo.s.s - 1], MP(nodo.s.f, nodo.s.s - 1)));
    }
    
  }

	return 0;
} 