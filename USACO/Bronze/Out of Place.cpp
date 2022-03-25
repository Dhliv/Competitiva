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
  cin.open("outofplace.in");
  ofstream cout("outofplace.out");

  int n; cin >> n;
  vector<int> p(n), sorted;

  FOR(i, 0, n) cin >> p[i];

  sorted = p;
  sort(sorted.begin(), sorted.end());

  int ans = -1;
  FOR(i, 0, n){
    if(p[i] != sorted[i]) ans++;
  }

  cout << ans << "\n";

  return 0;
}
