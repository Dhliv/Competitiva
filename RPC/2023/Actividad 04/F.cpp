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
 
using namespace std;
 
const ld EPSILON = 0.0000001;

char otherThan(char k, string &s){
  FOR(i, 0, s.size()){
    if(s[i] != k) return s[i];
  }

  return 'N';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(8);

  ld start[4] = {0, 90, 180, 270};
  map<char, int> ch;
  ch.insert(MP('N', 0));
  ch.insert(MP('E', 1));
  ch.insert(MP('S', 2));
  ch.insert(MP('W', 3));

  ld dos = 2.0, pw = 2.0;
  ld a, b;

  string as, bs; cin >> as >> bs;
  reverse(as.begin(), as.end());
  reverse(bs.begin(), bs.end());

  vector<vector<ld> > dir(4, vector<ld> (4));
  dir[0][1] = 90;
  dir[0][3] = -90;

  dir[1][2] = 90;
  dir[1][0] = -90;

  dir[2][3] = 90;
  dir[2][1] = -90;

  dir[3][0] = 90;
  dir[3][2] = -90;

  int id1 = ch[as[0]], id2 = ch[bs[0]];
  a = start[id1];
  b = start[id2];
  int dif1 = ch[otherThan(as[0], as)], dif2 = ch[otherThan(bs[0], bs)];
  int id;
  ld ax, diff = dir[id1][dif1];
  FOR(i, 1, as.size()){
    id = ch[as[i]];
    ax = id != id1 ? diff : -diff;
    a += ax/pw;
    pw *= dos;
  }

  diff = dir[id2][dif2];
  pw = dos;
  FOR(i, 1, bs.size()){
    id = ch[bs[i]];
    ax = id != id2 ? diff : -diff;
    b += ax/pw;
    pw *= dos;
  }

  if(fabs(a) > EPSILON and a < 0.0) a += 360.0;
  if(fabs(b) > EPSILON and b < 0.0) b += 360.0;

  if(fabs(a - b) > EPSILON and b < a) swap(a, b);
  cout << fixed << min(b - a, 360 - b + a);

  return 0;
}