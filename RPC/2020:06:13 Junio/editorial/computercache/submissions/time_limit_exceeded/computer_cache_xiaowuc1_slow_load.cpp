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
typedef pair<int, int> pii;
typedef pair<pii, int> state;

uint8_t cache[1 << 19];
vector<uint8_t> pref[1 << 19];

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> sizes;
  for(int i = 0; i < m; i++) {
    uint8_t sum = 0;
    pref[i].push_back(sum);
    int t;
    cin >> t;
    while(t--) {
      int now;
      cin >> now;
      pref[i].push_back(((uint8_t)now)-sum);
      sum += pref[i].back();
    }
  }
  while(q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int i, p;
      cin >> i >> p;
      i--;
      p--;
      uint8_t curr = 0;
      for(int a = 1; a < pref[i].size(); a++) {
        curr += pref[i][a];
        cache[p+a-1] = curr;
      }
    }
    else if(type == 2) {
      int x;
      cin >> x;
      cout << (int)cache[--x] << "\n";
    }
    else {
      int i, l, r;
      cin >> i >> l >> r;
      i--;
      pref[i][l]++;
      if(++r < pref[i].size()) pref[i][r]--;
    }
  }
}

int main() {
  solve();
}
