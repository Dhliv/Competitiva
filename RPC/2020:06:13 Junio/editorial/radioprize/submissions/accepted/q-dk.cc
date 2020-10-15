#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> T;
vector<vector<int>> E, W;

int chn[100001], cht[100001];
int64_t tot[100001];

void doit(int x, int p, int64_t curd, int64_t* w, int64_t* tw) {
  *w += curd;
  *tw += T[x]*curd;
  chn[x] = 1;
  cht[x] = T[x];
  for (int i = 0; i < E[x].size(); i++) if (E[x][i] != p) {
    doit(E[x][i], x, curd + W[x][i], w, tw);
    chn[x] += chn[E[x][i]];
    cht[x] += cht[E[x][i]];
  }
}

void doit2(int x, int p, int64_t w, int64_t tw) {
  tot[x] += tw + T[x]*w;
  for (int i = 0; i < E[x].size(); i++) if (E[x][i] != p) {
    doit2(E[x][i], x, w + W[x][i] * (int64_t)(chn[1]-2*chn[E[x][i]]), tw + W[x][i] * (int64_t)(cht[1]-2*cht[E[x][i]]));
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
    int64_t w = 0, tw = 0;
    doit(1, -1, 0, &w, &tw);
    doit2(1, -1, w, tw);
    for (int i = 1; i <= N; i++) cout << tot[i] << endl;
  }
}
