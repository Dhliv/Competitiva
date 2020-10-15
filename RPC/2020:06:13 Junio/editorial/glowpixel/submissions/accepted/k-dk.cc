#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N;
  while (cin >> N) {
    vector<tuple<int, char, int>> v;
    for (int i = 0; i < N; i++) {
      char ch;
      int T, M, A;
      cin >> ch >> T >> M >> A;
      if (ch == 'h') {
        v.emplace_back(T-A, ch, T-A+M-1);
      } else {
        v.emplace_back(T-A+M-1, ch, T-A);
      }
    }
    sort(v.begin(), v.end());
    vector<vector<int>> st;
    for (int sz = 1<<20; sz; sz /= 2) st.emplace_back(sz);
    int64_t ret = 0;
    for (auto const& it : v) {
      int y = get<2>(it) + (1<<19);
      if (get<1>(it) == 'h') {
        for (int i = 0; i < st.size(); i++, y /= 2) st[i][y]++;
      } else {
        for (int i = 0; i < st.size() && y < st[i].size(); i++, y /= 2) {
          if (y&1) ret += st[i][y++];
        }
      }
    }
    cout << ret << endl;
  }
}
