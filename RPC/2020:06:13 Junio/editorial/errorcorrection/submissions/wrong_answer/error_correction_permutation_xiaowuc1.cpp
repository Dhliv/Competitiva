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

mt19937 g1;
const int MAX_N = 5000;
string s[5000];
int n;
bitset<MAX_N> g[MAX_N];
void solve() {
  cin >> n;
  map<string, int> dp;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    dp[s[i]] = i;
  }
  for(int i = 0; i < n; i++) {
    for(int a = 0; a < s[i].size(); a++) {
      for(int b = 0; b < a; b++) {
        string t = s[i];
        swap(t[a], t[b]);
        if(dp.count(t)) {
          g[i].set(dp[t]);
        }
        swap(t[a], t[b]);
      }
    }
  }
  vector<int> v;
  for(int i = 0; i < n; i++) v.push_back(i);
  int ret = 0;
  for(int qqq = 0; qqq < 1e3; qqq++) {
    shuffle(v.begin(), v.end(), g1);
    bitset<MAX_N> curr;
    int cand = 0;
    for(int out: v) {
      if((curr & g[out]).count()) continue;
      curr.set(out);
      cand++;
    }
    ret = max(ret, cand);
  }
  cout << ret << "\n";
}

int main() {
  solve();
}
