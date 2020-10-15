#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 2048 ;
bool visited[2][MAX][MAX];
int x[MAX];
int y[MAX];
int score[MAX];
int n;

int det(int a, int b, int c, int d) {
  return a * d - b * c;
}

int compute_score(int orient, int pivot, int next) {
  if (visited[orient][pivot][next]) return 0;

  memset(score, 0, sizeof(score));
  while (!visited[orient][pivot][next]) {
    visited[orient][pivot][next] = true;
    score[pivot]++;

    int bx = x[next] - x[pivot], by = y[next] - y[pivot];
    int cx = -bx, cy = -by;
    int ix, iy, io;

    int c = pivot;
    int co = orient;
    for (int i = 0; i < n; i++) {
      ix = x[i] - x[next];
      iy = y[i] - y[next];
      io = orient;
      if (det(bx, by, ix, iy) > 0) {
        ix = -ix;
        iy = -iy;
        io = 1 - io;
      }
      if (det(cx, cy, ix, iy) > 0) {
        c = i;
        co = io;
        cx = ix;
        cy = iy;
      }
    }
    pivot = next;
    next = c;
    orient = co;
  }

  int best = 0;
  for (int i = 0; i < n; i++) if (best < score[i]) best = score[i];
  return best;
}

int main(int argc, char *argv[]) {
  memset(visited, 0, (1 << 21) * sizeof(bool));
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

  int best = 0;
  for (int o = 0; o < 2; o++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        int cur = compute_score(o, i, j);
        if (best < cur) best = cur;
      }
    }
  }

  cout << best << endl;
}
