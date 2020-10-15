#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C;
char g[1010][1010];

bool seen[1010][1010];
int doit(int x, int y) {
  if (g[y-1][x-1] == '\\' || g[y][x] == '\\' || g[y-1][x] == '/' || g[y][x-1] == '/') return 0;
  if (x == 1 || y == 1 || x == C+1 || y == R+1) return 2;
  if (seen[y][x]) return 0;
  seen[y][x] = true;
  int ret = 1;
  ret |= doit(x-1, y  );
  ret |= doit(x+1, y  );
  ret |= doit(x  , y-1);
  ret |= doit(x  , y+1);
  if (g[y-1][x-1] != '/' ) ret |= doit(x-1, y-1);
  if (g[y  ][x  ] != '/' ) ret |= doit(x+1, y+1);
  if (g[y-1][x  ] != '\\') ret |= doit(x+1, y-1);
  if (g[y  ][x-1] != '\\') ret |= doit(x-1, y+1);
  return ret;
}

int main() {
  while (cin >> R >> C) {
    memset(g, 0, sizeof(g));
    for (int y = 1; y <= R; y++) cin >> &g[y][1];
    memset(seen, 0, sizeof(seen));
    int ret = 0;
    for (int y = 2; y <= R; y++) for (int x = 2; x <= C; x++) ret += (doit(x, y) == 1);
    cout << ret << endl;
  }
}
