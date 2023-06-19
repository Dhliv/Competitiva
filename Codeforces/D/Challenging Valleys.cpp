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

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n;
  int l, r;

  while(t--){
    cin >> n;
    vector<int> p(n + 2);
    p[0] = p[n + 1] = INF;
    FOR(i, 0, n) cin >> p[i + 1];

    l = 1;
    int count = 0;
    FOR(i, 1, n + 2){
      if(p[l] == p[i]) continue;
      if(p[l - 1] > p[l] and p[l] < p[i]) count++;
      l = i;
    }

    cout << (count == 1 ? "YES" : "NO") << "\n";
  }
 
  return 0;
}