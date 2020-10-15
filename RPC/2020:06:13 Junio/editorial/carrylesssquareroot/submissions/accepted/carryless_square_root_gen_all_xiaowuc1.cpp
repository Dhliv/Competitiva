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

void fail() {
  cout << "-1\n";
  exit(0);
}

ll ret;
ll powTen[19];
int expectedSize;

void dfs(vector<int>& v, string& s) {
  if(v.size() == expectedSize) {
    ll cand = 0;
    for(int i = v.size()-1; i >= 0; i--) cand = 10*cand + v[i];
    ret = min(ret, cand);
    return;
  }
  for(int i = (v.size() == expectedSize-1 ? 1 : 0); i < 10; i++) {
    v.push_back(i);
    vector<int> sums;
    sums.resize(s.size());
    for(int a = 0; a < expectedSize; a++) {
      for(int b = 0; b < expectedSize; b++) {
        if(a >= v.size() || b >= v.size() || sums[a+b] < 0) sums[a+b] = -1;
        else sums[a+b] += v[a]*v[b];
      }
    }
    bool good = true;
    for(int k = 0; good && k < sums.size(); k++) {
      good = sums[k] < 0 || sums[k]%10 == s[k]-'0';
    }
    if(good) dfs(v, s);
    v.pop_back();
  }
}


void solve() {
  powTen[0] = 1;
  for(int i = 1; i < 19; i++) powTen[i] = 10 * powTen[i-1];
  string s;
  cin >> s;
  if(s.size()%2 == 0) fail();
  reverse(s.begin(), s.end());
  expectedSize = s.size()/2+1;
  ret = 1e18;
  vector<int> v;
  dfs(v, s);
  if(ret == 1e18) fail();
  cout << ret << "\n";
}

int main() {
  solve();
}
