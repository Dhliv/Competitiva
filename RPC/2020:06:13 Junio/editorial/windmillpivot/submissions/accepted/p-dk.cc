#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

inline bool upper(const PII& p) { return p.second > 0 || (p.second == 0 && p.first > 0); }

int main() {
  int N;
  while (cin >> N) {
    vector<PII> P(N);
    for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
    int ret = 0;
    for (int i = 0; i < N; i++) {
      vector<PII> v;
      for (int j = 0; j < P.size(); j++) if (j != i) {
        v.emplace_back(P[j].first-P[i].first, P[j].second-P[i].second);
      }
      sort(v.begin(), v.end(), [] (const PII& a, const PII& b) -> bool {
        int ax = upper(a) ? a.first : -a.first, ay = upper(a) ? a.second : -a.second;
        int bx = upper(b) ? b.first : -b.first, by = upper(b) ? b.second : -b.second;
        return ax*by > bx*ay;
      });
      int left = 0;
      for (auto const& p : v) left += upper(p);
      vector<int> rep(v.size()+1);
      for (auto const& p : v) {
        left += upper(p) ? -1 : 1;
        ret = max(ret, ++rep[left]);
      }
      for (auto const& p : v) {
        left += upper(p) ? 1 : -1;
        ret = max(ret, ++rep[left]);
      }
    }
    cout << ret << endl;
  }
}
