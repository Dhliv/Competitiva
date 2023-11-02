#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
 
using namespace std;

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n;

  while(t--){
    cin >> n;
    map<int, int> p;
    int x;
    FOR(i, 0, n){
      cin >> x;
      auto it = p.find(x);
      if(it != p.end()) it->s++;
      else p.insert(MP(x, 1));
    }

    if(p.size() > 2){
      cout << "NO\n";
      continue;
    }

    if(p.size() == 1){
      cout << "YES\n";
      continue;
    }

    vector<int> cap(2);
    int cnt = 0;
    for(auto it: p){
      cap[cnt++] = it.s;
    }

    if(abs(cap[0] - cap[1]) > 1) cout << "NO\n";
    else cout << "YES\n";
  }

  return 0;
}