#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

int main(){
  int n, q;
  string a, b;
  cin >> n;
  getline(cin, a);
  map<string, string> s;
  
  FOR(i, 0, n){
    getline(cin, a);
    getline(cin, b);
    s.insert(MP(a, b));
  }
  
  cin >> q;
  getline(cin, a);
  
  FOR(i, 0, q){
    getline(cin, a);
    cout << s[a] << "\n";
  }
  
  return 0;
}