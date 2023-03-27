#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
#define MAX 101005

using namespace std;
 
const ld EPSILON = 0.0000001;

string dirs[4] = {"DL", "DR", "UL", "UR"};
int rows, cols;
int dp[MAX][4];

int get_id(int i, int j){
  int id = 0;
  if(i == 1) return j;
  id += cols;
  if(j == cols) return i + id;
  id += rows - 1;
  if(i == rows) return j + id;
  id += cols - 1;
  return id + i;
}

bool manhattan(int &i, int &j, int &id, int &jd){
  return abs(i - id) == abs(j - jd);
}

bool check_pos(int i, int j, int id, int jd, string &dir){
  bool mnht = manhattan(i, j, id, jd);
  if(dir == "DL"){
    if(id >= i and jd <= j and mnht) return true;
  }else if(dir == "DR"){
    if(id >= i and jd >= j and mnht) return true;
  }else if(dir == "UL"){
    if(id <= i and jd <= j and mnht) return true;
  }else{
    if(id <= i and jd >= j and mnht) return true;
  }

  return false;
}

int bounce(int &i, int &j, string &dir){
  int row, col;

  if(dir[0] == 'U') row = i - 1;
  else row = rows - i;

  if(dir[1] == 'L') col = j - 1;
  else col = cols - j;

  int movement = min(row, col);
  if(dir[0] == 'U') i -= movement;
  else i += movement;

  if(dir[1] == 'L') j -= movement;
  else j += movement;

  string neo_dir = dir;

  if(i == rows and dir[0] == 'D') neo_dir[0] = 'U';
  else if(i == 1 and dir[0] == 'U') neo_dir[0] = 'D';

  if(j == cols and dir[1] == 'R') neo_dir[1] = 'L';
  else if(j == 1 and dir[1] == 'L') neo_dir[1] = 'R';

  FOR(k, 0, 4) if(neo_dir == dirs[k]) return k;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, x, y, xf, yf, idx, id, a, b; cin >> t;
  string dir, orDir;
  int bounces;

  FOR(ab, 1, t + 1){
    cin >> rows >> cols >> x >> y >> xf >> yf >> dir;
    a = x;
    b = y;
    orDir = dir;
    bounces = 0;

    memset(dp, -1, sizeof(dp));

    bool able = false;
    while(true){
      if(check_pos(x, y, xf, yf, dir)){
        able = true;
        break;
      }

      idx = bounce(x, y, dir);
      id = get_id(x, y);

      //cout << x << " " << y << " -> " << dirs[idx] << "; with id: " << id << endl;
      if(dp[id][idx] != -1) break;
      dp[id][idx] = 1;
      dir = dirs[idx];
      bounces++;

    }

    //if(ab == 143) cout << rows << "-" << cols << "-" << a << "-" << b << "-" << xf << "-" << yf << "-" << orDir;
    if(able) cout << bounces << "\n";
    else cout << "-1\n";
  }

  return 0;
}