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

const int MOD = 11092019 ;
int ret[256];
void solve() {
  string s;
  cin >> s;
  for(int i = 0; i < (int)s.size(); i++) ret[s[i]]++;
  ll ans = 1;
  for(int i = 'a'; i <= 'z'; i++) {
    ans *= ++ret[i];
    ans %= MOD;
  }
  cout << ans << "\n";
}

int main() {
  solve();
}
