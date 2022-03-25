#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("gymnastics.in");
  ofstream cout("gymnastics.out");

  int k, n; cin >> k >> n;
  map<pair<int, int>, int> p;
  vector<int> ite(n);

  FOR(ab, 0, k){
    FOR(i, 0, n) cin >> ite[i];

    FOR(i, 0, n - 1){
      FOR(j, i + 1, n){
        auto it = p.find(MP(ite[i], ite[j]));
        if(it == p.end()) p.insert(MP(MP(ite[i], ite[j]), 1));
        else it->s++;
      }
    }
  }

  int ans = 0;
  for(auto ele: p){
    if(k == ele.s) ans++;
  }

  cout << ans << "\n";

  return 0;
}
