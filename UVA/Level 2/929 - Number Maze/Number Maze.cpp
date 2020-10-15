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

int F[4] = {1, -1, 0, 0};
int C[4] = {0, 0, 1, -1};

using namespace std;

int main() {
  int cases, fil, col, val, x, y;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> fil >> col;
    
    vector<vector<short int> > ady(fil, vector<short int> (col));
    
    FOR(i, 0, fil){
      FOR(j, 0, col)
        cin >> ady[i][j];
    }
    
    priority_queue<pair<int, pair<int, int > > > pq;
    pq.push(MP(0, MP(0, 0)));
    vector<vector<int> > visit(fil, vector<int> (col)), dist(fil, vector<int> (col, INF));
    dist[0][0] = ady[0][0];
    
    while(!pq.empty()){
      x = pq.top().s.f, y = pq.top().s.s;
      pq.pop();
      
      if(visit[x][y]) continue;
      visit[x][y] = 1;
      
      FOR(i, 0, 4){
        if(x + F[i] < fil and x + F[i] >= 0){
          if(y + C[i] < col and y + C[i] >= 0){
            if(visit[x + F[i]][y + C[i]] == 0){
              if(dist[x + F[i]][y + C[i]] > dist[x][y] + ady[x + F[i]][y + C[i]]){
                dist[x + F[i]][y + C[i]] = dist[x][y] + ady[x + F[i]][y + C[i]];
                pq.push(MP(-dist[x + F[i]][y + C[i]], MP(x + F[i], y + C[i])));
              }
            }
          }
        }
      }
    }
    
    cout << dist[fil - 1][col - 1] << "\n";
  }
  
	return 0;
}