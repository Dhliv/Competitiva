#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define PI 3.1415926535897932384626

int main() {
  int N;
  while (cin >> N) {
    vector<pair<double, double>> a;
    double d = 0.0, v = 0.0;
    for (int i = 0; i < N; i++) {
      double T, S, A;
      cin >> T >> S >> A;
      d += max(0.0, T-S*min(A, 2*PI-A));
      double a1 = A-min(PI, T/S), a2 = A+min(PI, T/S);
      if (a1 < 0.0 ) { v += S; a1 += 2*PI; }
      if (a2 > 2*PI) { v -= S; a2 -= 2*PI; }
      a.emplace_back(a1, S);
      a.emplace_back(A, -2*S);
      a.emplace_back(a2, S);
    }
    sort(a.begin(), a.end());
    double ret = d, x = 0.0;
    for (auto const& it : a) {
      d += v * (it.first - x);
      ret = max(ret, d);
      x = it.first;
      v += it.second;
    }
    printf("%.9lf\n", ret);
  }
}
