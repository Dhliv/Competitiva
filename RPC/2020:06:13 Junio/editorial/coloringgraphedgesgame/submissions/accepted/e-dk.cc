#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, A, B;
  while (cin >> N >> M) {
    vector<vector<int>> g(N+1);
    for (int i = 0; i < M; i++) {
      cin >> A >> B;
      g[A].push_back(B);
      g[B].push_back(A);
    }
    vector<int> seen(N+1), q{1};
    seen[1] = true;
    int ret;
    for (ret = 0; !seen[N]; ret++) {
      vector<int> q2;
      for (auto x : q) {
        for (auto y : g[x]) if (!seen[y]) {
          q2.push_back(y);
          seen[y] = true;
        }
      }
      q.swap(q2);
    }
    cout << ret-1 << endl;
  }
}
