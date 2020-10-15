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

int fil, col, quers, ans;
int filas[4] = {0, -1, 0, 1}, colums[4] = {1, 0, -1, 0};
vector<int> valores(26, 0);

void move(vector<string> &ele, pair<int, int> &pos, int dir){
  if(pos.f + filas[dir] < fil and pos.f + filas[dir] >= 0){
    if(pos.s + colums[dir] < col and pos.s + colums[dir] >= 0){
      if(ele[pos.f + filas[dir]][pos.s + colums[dir]] != '#'){
        pos = MP(pos.f + filas[dir], pos.s + colums[dir]);
        if(ele[pos.f][pos.s] == '*'){
          ans++;
          ele[pos.f][pos.s] = '.';
        }
      }
    }
  }
}

int main() {
  int actual;
  pair<int, int> posi;
  valores['N' - 'A'] = 1;
  valores['L' - 'A'] = 0;
  valores['O' - 'A'] = 2;
  valores['S' - 'A'] = 3;
  
  while(cin >> fil >> col >> quers, quers+fil+col){
    vector<string> ele(fil);
    string ent;
    ans = 0;
    
    FOR(i, 0, fil)
      cin >> ele[i];
    
    FOR(i, 0, fil){
      FOR(j, 0, col){
        if(ele[i][j] != '.' and ele[i][j] != '*' and ele[i][j] != '#'){
          actual = valores[ele[i][j] - 'A'];
          posi = MP(i, j);
        }
      }
    }
    
    cin >> ent;
    FOR(i, 0, quers){
      if(ent[i] == 'F'){
        move(ele, posi, actual);
      }else if(ent[i] == 'E')
        actual = (actual + 1)%4;
      else{
        actual = (actual + 3)%4;
      }
    }
    
    cout << ans << "\n";
  }

	return 0;
}