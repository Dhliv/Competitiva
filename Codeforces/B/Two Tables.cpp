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

int W, H;

struct rect{
  int x1, x2, y1, y2;
};

int getMiniDist(rect &a, rect &b, int id){
  int x = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
  int y = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));

  if(x == 0 or y == 0) return 0;
  int mini = INF;

  if(id == 0){ // move to right and up
    if(a.y2 + abs(b.y2 - a.y1) <= H) mini = abs(b.y2 - a.y1);
    if(a.x2 + abs(b.x2 - a.x1) <= W) mini = min(mini, abs(b.x2 - a.x1));
  }else if(id == 1){ // move to right and down
    if(a.y1 - abs(b.y1 - a.y2) >= 0) mini = abs(b.y1 - a.y2);
    if(a.x2 + abs(b.x2 - a.x1) <= W) mini = min(mini, abs(b.x2 - a.x1));
  }else if(id == 2){ // move to left and down
    if(a.y1 - abs(b.y1 - a.y2) >= 0) mini = abs(b.y1 - a.y2);
    if(a.x1 - abs(b.x1 - a.x2) >= 0) mini = min(mini, abs(b.x1 - a.x2));
  }else{ // move to left and up
    if(a.y2 + abs(b.y2 - a.y1) <= H) mini = abs(b.y2 - a.y1);
    if(a.x1 - abs(b.x1 - a.x2) >= 0) mini = min(mini, abs(b.x1 - a.x2));
  }

  return mini;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int mini, w, h, t; cin >> t;
  rect a, b;

  FOR(ab, 0, t){
    cin >> W >> H;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    mini = INF;
    cin >> w >> h;

    b.x1 = 0; b.y1 = 0; b.x2 = w; b.y2 = h;
    mini = min(mini, getMiniDist(a, b, 0));

    b.x1 = 0; b.y1 = H - h; b.x2 = w; b.y2 = H;
    mini = min(mini, getMiniDist(a, b, 1));

    b.x1 = W - w; b.y1 = H - h; b.x2 = W; b.y2 = H;
    mini = min(mini, getMiniDist(a, b, 2));

    b.x1 = W - w; b.y1 = 0; b.x2 = W; b.y2 = h;
    mini = min(mini, getMiniDist(a, b, 3));

    if(mini == INF) cout << "-1\n";
    else cout << mini << "\n";
  }

  return 0;
}
