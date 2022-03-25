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
 
using namespace std;

struct cow{
  int x, y;
  char dir;
};

struct info{
  int x, y, i, j, dist;

  void operator() (int i, int j, int x, int y, int dist){
    this->x = x;
    this->y = y;
    this->i = i;
    this->j = j;
    this->dist = dist;
  }
};

bool comp(info &a, info &b){
  return a.dist < b.dist;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x, y; cin >> n;
  vector<cow> p(n);
  vector<info> q;
  info aux;

  FOR(i, 0, n) cin >> p[i].dir >> p[i].x >> p[i].y;

  FOR(i, 0, n){
    FOR(j, 0, n){
      if(i == j) continue;

      if(p[i].dir != p[j].dir){
        x = max(p[i].x, p[j].x);
        y = max(p[i].y, p[j].y);

        if(p[i].dir == 'E'){
          if(p[i].x > p[j].x or p[i].y < p[j].y or (x - p[i].x) <= (y - p[j].y)) continue;
          aux(i, j, x, y, x - p[i].x);
          q.PB(aux);
        }else{
          if(p[i].x < p[j].x or p[i].y > p[j].y or (y - p[i].y) <= (x - p[j].x)) continue;
          aux(i, j, x, y, y - p[i].y);
          q.PB(aux);
        }
      }
    }
  }

  sort(q.begin(), q.end(), comp);
  vector<int> maxis(n, INF);
  vector<pair<int, int> > blocks(n);

  FOR(i, 0, q.size()){

    if(maxis[q[i].i] == INF and maxis[q[i].j] == INF){
      maxis[q[i].i] = q[i].dist;
      blocks[q[i].i] = MP(q[i].x, q[i].y);
    }else if(maxis[q[i].i] != INF) continue;
    else if(maxis[q[i].j] != INF){
      if(p[q[i].i].dir == 'N'){
        if(p[q[i].i].x <= blocks[q[i].j].f){
          maxis[q[i].i] = q[i].dist;
          blocks[q[i].i] = MP(q[i].x, q[i].y);
        }
      }else{
        if(p[q[i].i].y <= blocks[q[i].j].s){
          maxis[q[i].i] = q[i].dist;
          blocks[q[i].i] = MP(q[i].x, q[i].y);
        }
      }
    }
  }

  FOR(i, 0, n){
    if(maxis[i] == INF) cout << "Infinity\n";
    else cout << maxis[i] << "\n";
  }
  
  return 0;
}
