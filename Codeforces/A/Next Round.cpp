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

struct dt{
  char k;
  int pos;

  dt(){}
  dt(char k, int pos) : k(k), pos(pos) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k; cin >> n >> k;
  vector<int> p(n); FOR(i, 0, n) cin >> p[i];
  int val = p[k - 1];
  if(val == 0) val++;

  int cnt;
  FOR(i, 0, n){
    if(p[i] < val) break;
    cnt++;
  }


  cout << cnt << "\n";

  return 0;
}