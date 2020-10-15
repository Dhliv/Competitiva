#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

// Returns -1 for unmatched items.
// Complexity: O(V*E)
VI BipartiteMatch(const VVI &mat, VI *back_match = NULL) {
  int max_item = -1;
  VI fmat(mat.size(), -1), seen(mat.size(), -1), prev(mat.size());
  for (auto row : mat) if (row.size()) max_item = max(max_item, *max_element(row.begin(), row.end()));
  VI bmat(max_item+1, -1);

  for (int i = 0; i < mat.size(); i++) {
    VI q(1, i);
    seen[i] = i; prev[i] = -1;
    int x, y;
    while (!q.empty()) {
      x = q.back(); q.pop_back();
      for (auto it : mat[x]) {
        int bm = bmat[it];
        if (bm == -1) {y = it; goto found_match;}
        if (seen[bm] < i) {
          seen[bm] = i; prev[bm] = x;
          q.push_back(bm);
        }
      }
    }
    continue;
found_match:
    while (x != -1) {
      bmat[y] = x;
      swap(y, fmat[x]);
      x = prev[x];
    }
  }

  if (back_match) back_match->swap(bmat);
  return fmat;
}

int main() {
  int N;
  while (cin >> N) {
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    VVI mat(N);
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      int diff = 0;
      for (int k = 0; k < S[i].size(); k++) diff += (S[i][k] != S[j][k]);
      if (diff == 2) mat[i].push_back(j);
    }
    VI fmat = BipartiteMatch(mat);
    int ret = 2*N;
    for (auto x : fmat) ret -= (x != -1);
    cout << ret/2 << endl;
  }
}
