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

  int n; cin >> n;
  int a, b;
  a = b = 0;
  vector<int> p1(n), p2(n);
  FOR(i, 0, n) cin >> p1[i];
  FOR(i, 0, n) cin >> p2[i];

  FOR(i, 0, n){
    FOR(j, 0, n){
      if(p1[i] > p2[j]) a++;
      if(p2[j] > p1[i]) b++;
    }
  }

  if(a == b) cout << "tie\n";
  else if(a > b) cout << "first\n";
  else cout << "second\n";

  return 0;
}