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

string g[50];
int n;

void die() {
  cout << "0\n";
  exit(0);
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> g[i];
  for(int i = 0; i < n; i++) {
    int hs = 0;
    int vs = 0;
    for(int j = 0; j < n; j++) {
      hs += g[i][j] == 'B';
      vs += g[j][i] == 'B';
    }
    if(hs != n/2) die();
    if(vs != n/2) die();
  }
  for(int i = 0; i+2 < n; i++) {
    for(int j = 0; j < n; j++) {
      if(g[i][j] == g[i+1][j] && g[i+1][j] == g[i+2][j]) die();
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j+2 < n; j++) {
      if(g[i][j] == g[i][j+1] && g[i][j+1] == g[i][j+2]) die();
    }
  }
  cout << "1\n";
}

int main() {
  solve();
}
