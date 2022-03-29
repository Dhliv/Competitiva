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

struct rect{
  bool ini;
  int x, y1, y2;

  void operator()(int x, int y1, int y2, bool ini){
    this->ini = ini;
    this->x = x;
    this->y1 = y1;
    this->y2 = y2;
  }
};

bool comp(rect &a, rect &b){
  return a.x < b.x;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x1, x2, y1, y2, l = 0; cin >> n;
  rect a, b;
  vector<rect> p(2*n);

  FOR(i, 0, n){
    cin >> x1 >> y1 >> x2 >> y2;
    p[l++](x1, y1, y2, true);
    p[l++](x2, y1, y2, false);
  }
  
  sort(p.begin(), p.end(), comp);

  bool able = false;
  set<int> has;
  has.insert(INF);

  FOR(i, 0, 2*n){
    if(p[i].ini){
      auto it = has.lower_bound(p[i].y1);
      if(*it <= p[i].y2){
        able = true;
        break;
      }

      has.insert(p[i].y1);
      has.insert(p[i].y2);
    }else{
      has.erase(p[i].y1);
      has.erase(p[i].y2);

      auto it = has.lower_bound(p[i].y1);
      if(*it <= p[i].y2){
        able = true;
        break;
      }
    }
  }

  if(able) cout << "1\n";
  else cout << "0\n";

  return 0;
}
