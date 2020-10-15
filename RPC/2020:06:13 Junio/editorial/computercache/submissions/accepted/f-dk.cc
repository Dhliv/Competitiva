#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> X;
vector<vector<vector<vector<int>>>> Xadd;

int main() {
  int N, M, Q, sz, C, I, P, L, R;
  while (cin >> N >> M >> Q) {
    X = vector<vector<int>>(M+1);
    Xadd = vector<vector<vector<vector<int>>>>(M+1);
    for (int I = 1; I <= M; I++) {
      cin >> sz;
      X[I].resize(sz);
      for (int j = 0; j < sz; j++) cin >> X[I][j];
      for (; sz; sz /= 2) Xadd[I].emplace_back(sz);
    }

    vector<vector<int>> x, xs, xt;
    for (int sz = N+1; sz; sz /= 2) { x.emplace_back(sz); xs.emplace_back(sz); xt.emplace_back(sz); }
    for (int t = 1; t <= Q; t++) {
      cin >> C;
      if (C == 1) {
        cin >> I >> P;
        L = P; R = P+X[I].size();
        for (int i = 0; i < x.size(); i++, L /= 2, R /= 2) {
          if (L<R && (L&1)) { x[i][L] = I; xs[i][L] = P; xt[i][L] = t; L++; }
          if (L<R && (R&1)) { R--; x[i][R] = I; xs[i][R] = P; xt[i][R] = t; }
        }
      } else if (C == 2) {
        cin >> P;
        int px = 0, pxs = 0, pxt = 0, ret = 0;
        for (int i = 0, p = P; i < x.size() && p < x[i].size(); i++, p /= 2) if (xt[i][p] > pxt) {
          px = x[i][p]; pxs = xs[i][p]; pxt = xt[i][p];
        }
        if (px) {
          P -= pxs;
          ret = X[px][P];
          for (int i = 0; i < Xadd[px].size() && P < Xadd[px][i].size(); i++, P /= 2) {
            ret += lower_bound(Xadd[px][i][P].begin(), Xadd[px][i][P].end(), pxt) - Xadd[px][i][P].begin();
          }
        }
        cout << (ret&255) << endl;
      } else {
        cin >> I >> L >> R;
        L--;
        for (int i = 0; i < Xadd[I].size() && L < R; i++, L /= 2, R /= 2) {
          if (L<R && (L&1)) Xadd[I][i][L++].push_back(t);
          if (L<R && (R&1)) Xadd[I][i][--R].push_back(t);
        }
      }
    }
  }
}
