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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int maxx, maxy, x, y, sen;
  string ent;
  char k;
  vector<char> let{'N', 'E', 'S', 'W'};
  map<char, int> ori;
  FOR(i, 0 , 4) ori.insert(MP(let[i], i));
  vector<int> dy{1, 0, -1, 0}, dx{0, 1, 0, -1};
  bool lost;
  
  cin >> maxx >> maxy;
  
  vector<vector<int> > grid(maxx + 1, vector<int> (maxy + 1, 0));
  
  while(cin >> x >> y >> k){
    sen = ori.find(k)->s;
    cin >> ent;
    lost = false;
    
    FOR(i, 0, ent.size()){
      if(ent[i] == 'R'){
        sen++;
        sen %= 4;
      }else if(ent[i] == 'L'){
        sen--;
        if(sen < 0) sen = 3;
      }else{
        if(((x + dx[sen]) > maxx or (x + dx[sen]) < 0) and grid[x][y]){}
        else if(((y + dy[sen]) > maxy or (y + dy[sen]) < 0) and grid[x][y]){}
        else{
          x += dx[sen];
          y += dy[sen];
          
          if(x > maxx or x < 0){
            lost = true;
            if(x < 0) x++;
            else x--;
            grid[x][y] = 1;
            break;
          }else if(y > maxy or y < 0){
            lost = true;
            if(y < 0) y++;
            else y--;
            grid[x][y] = 1;
            break;
          }
        }
      }
    }
    
    cout << x << " " << y << " " << let[sen];
    if(lost)  cout << " LOST\n";
    else cout << "\n";
  }
  
  return 0;
}