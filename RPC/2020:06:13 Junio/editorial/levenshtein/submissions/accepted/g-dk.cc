#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  string A, S;
  while (cin >> A >> S) {
    set<string> ret;
    for (int i = 0; i <  S.size(); i++) for (char ch : A) ret.insert(S.substr(0, i) + ch + S.substr(i+1));
    for (int i = 0; i <= S.size(); i++) for (char ch : A) ret.insert(S.substr(0, i) + ch + S.substr(i));
    for (int i = 0; i <  S.size(); i++) ret.insert(S.substr(0, i) + S.substr(i+1));
    ret.erase(S);
    for (auto s : ret) cout << s << endl;
  }
}
