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
#define MAX 5001

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
    vector<int> ans(n, 1);
    map<int, int> has, p;
    int x;
    FOR(i, 0, n){
      cin >> x;
      auto it = has.find(x);
      if(it != has.end()){
        p.insert(MP(x, i));
        it->s = i;
      }else has.insert(MP(x, i));
    }

    if(p.size() < 2){
      cout << "-1\n";
      continue;
    }

    int cnt = 1;
    for(const auto it: p){
      if(cnt == 3) break;
      cnt++;
      ans[it.s] = cnt;
    }

    FOR(i, 0, n) cout << ans[i] << " ";
    cout << "\n";
  }

  return 0;
}