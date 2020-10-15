#include <iostream>
using namespace std;

int main() {
  int A, B;
  while (cin >> A >> B) {
    int ret = 0;
    while (A > B) {
      if (A&1) { A++; ret++; }
      A /= 2; ret++;
    }
    ret += B-A;
    cout << ret << endl;
  }
}
