#include <iostream>
using namespace std;

int main() {
  int N;
  while (cin >> N) {
    cout << ((N&1) ? "Either" : (N&2) ? "Odd" : "Even") << endl;
  }
}
