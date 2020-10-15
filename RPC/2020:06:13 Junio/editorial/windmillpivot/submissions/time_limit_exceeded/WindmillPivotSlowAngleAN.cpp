#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 2048 ;

bool visited[2][MAX][MAX];
int x[MAX];
int y[MAX];
unsigned int ang[MAX][MAX];
int score[MAX];
int n;

const double PI = 3.14159265358979 ;
const double TAU = 2 * PI;
const double FACTOR = 4294967296.0 / TAU;
unsigned int fixang(double a) {
  if (a < 0) a += TAU ;
  return (unsigned int) (a * FACTOR);
}

int compute_score(int orient, int pivot, int next) {
  if (visited[orient][pivot][next]) return 0;

  memset(score, 0, sizeof(score));
  while (!visited[orient][pivot][next]) {
    visited[orient][pivot][next] = true;
    score[pivot]++;

    unsigned int bang = orient ? ang[next][pivot] : ang[pivot][next];
    int io;

    int c = pivot;
    unsigned int carc = 2147483647;
    int co = orient;
    unsigned int arc;
    for (int i = 0; i < n; i++) {
      if (i == pivot || i == next) continue;
      arc = bang - ang[next][i];
      io = 0;
      if (arc > 2147483647) {
        arc -= 2147483648;
        io = 1;
      }
      if (carc > arc) {
        c = i;
        co = io;
        carc = arc;
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

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      ang[i][j] = fixang(atan2(y[j] - y[i], x[j] - x[i]));
    }
  }

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
