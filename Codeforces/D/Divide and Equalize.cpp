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
 
const ld EPSILON = 0.000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  const int MAX = 1000;
  vector<int> prs(1, 2);
  vector<int> notp(MAX);
  for(ll i = 3; i < MAX; i += 2){
    if(notp[i]) continue;
    prs.PB(i);
    for(ll j = i*i; j < MAX; j += i) notp[j] = 1;
  }

  int t; cin >> t;
  int n;

  while(t--){
    cin >> n;
    int x;
    vector<int> hs(prs.size());
    map<int, int> hsm;

    FOR(i, 0, n){
      cin >> x;

      for(int j = 0; j < prs.size() and x > 1; ++j){
        while(x%prs[j] == 0){
          hs[j]++;
          x /= prs[j];
        }
      }

      if(x > 1){
        auto it = hsm.find(x);
        if(it != hsm.end()) it->s++;
        else hsm.insert(MP(x, 1));
      }
    }

    bool able = true;
    FOR(i, 0, prs.size()){
      if(hs[i] == 0) continue;
      if(hs[i]%n){
        able = false;
        break;
      }
    }

    if(able){
      for(const auto it: hsm){
        if(it.s%n){
          able = false;
          break;
        }
      }
    }

    cout << (able ? "YES" : "NO") << "\n";
  }

  return 0;
}