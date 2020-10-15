#include <iostream>
#include <string>
using namespace std;

string N, cur, ret;

void doit(int i) {
  if (i < 0) { ret = min(ret, cur); return; }
  int maxdig = (i < N.size()/2) ? '0' : '9';
  for (cur[i] = '0'; cur[i] <= maxdig; cur[i]++) {
    int dig = 0;
    for (int j = 0; i+j < N.size(); j++) dig += (cur[i+j]-'0')*(cur[N.size()-1-j]-'0');
    if (dig%10+'0' == N[i]) doit(i-1);
  }
}

int main() {
  while (cin >> N) {
    ret = cur = string(N.size(), 'X');
    doit(N.size()-1);
    if (ret[0] == 'X') {
      cout << -1 << endl;
    } else {
      while (ret[0] == '0') ret = ret.substr(1);
      cout << ret << endl;
    }
  }
}
