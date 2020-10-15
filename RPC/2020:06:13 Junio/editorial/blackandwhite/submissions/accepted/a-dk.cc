#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  while (cin >> N) {
    vector<string> g(N);
    for (int i = 0; i < N; i++) cin >> g[i];
    int ret = 1;
    for (int swp = 0; swp < 2; swp++) {
      for (int y = 0; y < N; y++) {
        int b = 0;
        for (int x = 0; x < N; x++) b += (g[y][x] == 'B');
        if (2*b != N) ret = 0;
        for (int x = 0; x+2 < N; x++) if (g[y][x] == g[y][x+1] && g[y][x] == g[y][x+2]) ret = 0;
      }
      for (int y = 0; y < N; y++) for (int x = y; x < N; x++) swap(g[y][x], g[x][y]);
    }
    cout << ret << endl;
  }
}
