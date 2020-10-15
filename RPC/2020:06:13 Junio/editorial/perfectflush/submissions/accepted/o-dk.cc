#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  while (cin >> N >> K) {
    vector<int> v(N), last(K+1), u(K+1), ret;
    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 0; i < N; i++) last[v[i]] = i;
    for (int i = 0; i < N; i++) if (!u[v[i]]) {
      while (ret.size() > 0 && v[i] < ret.back() && i < last[ret.back()]) {
        u[ret.back()] = 0;
        ret.pop_back();
      }
      u[v[i]] = 1;
      ret.push_back(v[i]);
    }
    for (int i = 0; i < ret.size(); i++) {
      if (i) cout << ' ';
      cout << ret[i];
    }
    cout << endl;
  }
}
