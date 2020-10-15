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
  int r, c, ini, x, y, steps, sen, sci, fin;
  string ent;
  bool ciclo;
  vector<int> d(26), dx{0, -1, 0, 1}, dy{-1, 0, 1, 0};
  d['N' - 'A'] = 0;
  d['W' - 'A'] = 1;
  d['S' - 'A'] = 2;
  d['E' - 'A'] = 3;
  
  while(cin >> r >> c >> ini, r + c + ini){
    vector<string> grid(r);
    x = ini - 1;
    y =  0;
    steps = sci = 1;
    ciclo = false;
    vector<vector<int> > seen(c, vector<int> (r));
    
    FOR(i, 0, r) cin >> grid[i];
    seen[x][y] = 1;
    
    while(true){
      sen = d[grid[y][x] - 'A'];
      x += dx[sen];
      y += dy[sen];
      if((x >= c or x < 0) or (y >= r or y < 0)) break;
      else if(seen[x][y] == 0) seen[x][y] = 1;
      else{
        ciclo = true;
        break;
      }
      steps++;
    }
    
    if(!ciclo) cout << steps << " step(s) to exit\n";
    else{
      ini = x;
      fin = y;
      while(true){
        sen = d[grid[y][x] - 'A'];
        x += dx[sen];
        y += dy[sen];
        if(x == ini and y == fin) break;
        sci++;
      }
      
      cout << steps - sci << " step(s) before a loop of " << sci << " step(s)\n";
    }
  }
  
  return 0;
}