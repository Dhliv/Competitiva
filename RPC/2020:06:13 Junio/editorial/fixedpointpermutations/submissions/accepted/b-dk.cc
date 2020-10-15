#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int64_t LIM = 1000000000000000001LL ;

// Return a+b*c, capped to LIM.
int64_t cap(int64_t a, int64_t b, int64_t c) {
  double v = a + double(b)*c;
  if (v > 1.1*LIM) return LIM;
  return min(LIM, a+b*c);
}

// Return # of m-match permutations of cards, some of which match remaining slots and some of which are free.
int64_t memo[51][51][51];
int64_t doit(int m, int mat, int nmat) {
  if (m > mat || m < 0 || mat < 0 || nmat < 0) return 0;
  if (mat == 0 && nmat == 0) return 1;
  int64_t& ret = memo[m][mat][nmat];
  if (ret != -1) return ret;
  if (mat == 0) return ret = cap(0, nmat, doit(m, mat, nmat-1));

  // Try all possibilities in next matched slot.
  ret = cap(0, nmat, doit(m, mat-1, nmat));  // Use non-matched card in slot.
  if (m > 0) ret = cap(ret, 1, doit(m-1, mat-1, nmat));  // Use matching card in slot.
  if (mat > 1) ret = cap(ret, (mat-1), doit(m, mat-2, nmat+1));  // Use other matched card in slot.
  return ret;
}


int main() {
  memset(memo, -1, sizeof(memo));
  int N, M;
  int64_t K;
  while (cin >> N >> M >> K) {
    vector<int> ret, c;
    for (int x = 1; x <= N; x++) c.push_back(x);
    for (int i = 1, m = M; i <= N; i++) {
      for (int j = 0; ; j++) {
        if (j >= c.size()) goto fail;
        int m2 = m - (c[j]==i), mat = 0, nmat = 0;
        for (int k = 0; k < c.size(); k++) if (k != j) (c[k] > i ? mat : nmat) += 1;
        int64_t v = doit(m2, mat, nmat);
        if (v >= K) {
          m = m2;
          ret.push_back(c[j]);
          c.erase(c.begin()+j);
          break;
        }
        K -= v;
      }
    }

    for (int i = 0; i < ret.size(); i++) {
      if (i) cout << ' ';
      cout << ret[i];
    }
    cout << endl;
    continue;
fail:
    cout << -1 << endl;
  }
}
