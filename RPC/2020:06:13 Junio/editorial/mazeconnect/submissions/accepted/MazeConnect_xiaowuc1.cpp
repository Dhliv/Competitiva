#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000;
char g[2*MAX_SIZE+2][2*MAX_SIZE+2];
int par[5 * MAX_SIZE * MAX_SIZE];
int find(int x) {
  return par[x] == x ? x : (par[x] = find(par[x]));
}
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return false;
  par[x] = y;
  return true;
}
int r, c;
void solve() {
  cin >> r >> c;
  memset(g, '.', sizeof(g));
  for(int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < c; j++) {
      if(s[j] == '.') continue;
      if(s[j] == '/') {
        g[2*i+1][2*j+2] = '#';
        g[2*i+2][2*j+1] = '#';
      }
      else {
        g[2*i+1][2*j+1] = '#';
        g[2*i+2][2*j+2] = '#';
      }
    }
  }
  int maxR = 2 * r + 2;
  int maxC = 2 * c + 2;
  int comps = 0;
  for(int i = 0; i < maxR; i++) {
    for(int j = 0; j < maxC; j++) {
      if(g[i][j] == '#') continue;
      comps++;
      par[i*maxC+j] = i*maxC+j;
      if(i > 0 && g[i-1][j] == '.' && merge((i-1)*maxC + j, i*maxC + j)) comps--;
      if(j > 0 && g[i][j-1] == '.' && merge(i*maxC + j - 1, i*maxC + j)) comps--;
    }
  }
  cout << comps-1 << "\n";
}

int main() {
  solve();
}
