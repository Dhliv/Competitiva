#include <iostream>
#include <vector>
using namespace std;

int main() {
  int R, C, A, B;
  while (cin >> R >> C >> A >> B) {
    vector<int> a(A), b(B);
    for (int i = 0; i < A; i++) cin >> a[i];
    for (int i = 0; i < B; i++) cin >> b[i];
    for (int i = 0; i < A; i++) for (int ii = 0; ii < a[i]; ii++) {
      for (int j = 0; j < B; j++) for (int jj = 0; jj < b[j]; jj++) {
        cout << (((i^j)&1) ? 'W' : 'B');
      }
      cout << endl;
    }
  }
}
