#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N, M;
  while (cin >> N >> M) {
    vector<string> bad(N);
    for (int i = 0; i < N; i++) cin >> bad[i];
    for (int i = 0; i < M; i++) {
      string S;
      cin >> S;
      for (int i = 0; i < S.size(); i++) if (isdigit(S[i])) S[i] = "OLZE?SBTB?"[S[i]-'0'];
      bool ret = false;
      for (auto b : bad) if (S.find(b) != -1) ret = true;
      cout << (ret ? "INVALID" : "VALID") << endl;
    }
  }
}
