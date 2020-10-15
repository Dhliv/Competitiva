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

typedef long long ll;

int rs[1000];
int cs[1000];
int r, c, a, b;
void solve() {
  cin >> r >> c >> a >> b;
  for(int i = 0; i < a; i++) {
    cin >> rs[i];
  }
  for(int j = 0; j < b; j++) {
    cin >> cs[j];
  }
  for(int i = 0; i < a; i++) {
    for(int x = 0; x < rs[i]; x++) {
      char cand = (i%2 == 0 ? 'B' : 'W');
      for(int j = 0; j < b; j++) {
        int y = cs[j];
        while(y--) cout << cand;
        cand = ('B' + 'W' - cand);
      }
      cout << "\n";
    }
  }
}

int main() {
  solve();
}
