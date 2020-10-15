#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> T;
vector<vector<int>> E, W;

int ndn[100001];
int64_t tot[100001];

int64_t doit(int x, int p, int t, int curd) {
  int64_t ret = (T[x]==t ? curd : 0);
  ndn[x] = (T[x]==t);
  for (int i = 0; i < E[x].size(); i++) if (E[x][i] != p) {
    ret += doit(E[x][i], x, t, curd + W[x][i]);
    ndn[x] += ndn[E[x][i]];
  }
  return ret;
}

void doit2(int x, int p, int t, int n, int64_t curw) {
  tot[x] += (t+T[x]) * curw;
  for (int i = 0; i < E[x].size(); i++) if (E[x][i] != p) {
    doit2(E[x][i], x, t, n, curw + W[x][i] * (n-2*ndn[E[x][i]]));
  }
}

int main() {
  while (cin >> N) {
    memset(tot, 0, sizeof(tot));
    T = vector<int>(N+1);
    E = W = vector<vector<int>>(N+1);
    for (int i = 1; i <= N; i++) cin >> T[i];
    for (int i = 0; i < N-1; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      E[x].push_back(y); W[x].push_back(w);
      E[y].push_back(x); W[y].push_back(w);
    }

    for (int t = 1; t <= 1000; t++) {
      int64_t w = doit(1, -1, t, 0);
      doit2(1, -1, t, ndn[1], w);
    }

    for (int i = 1; i <= N; i++) cout << tot[i] << endl;
  }
}
