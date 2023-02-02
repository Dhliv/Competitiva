#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
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

  const int MAX = 999999;

  vector<int> nums;
  int mult = 1;

  while(mult < MAX){
    FOR(i, 1, 10) nums.PB(i*mult);
    mult *= 10;
  }

  nums.PB(INF);

  int t; cin >> t;
  int n;

  while(t--){
    cin >> n;

    cout << upper_bound(nums.begin(), nums.end(), n) - nums.begin() << "\n";
  }
 
  return 0;
}