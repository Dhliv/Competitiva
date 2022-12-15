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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  if(n == 1) cout << "1\n";
  else if(n <= 3) cout << "NO SOLUTION\n";
  else{
    for(int i = (n & 1 ? n : n - 1); i > 0; i -= 2) cout << i << " ";
    for(int i = (n & 1 ? n - 1 : n); i > 2; i -= 2) cout << i << " ";
    cout << "2\n";
  }

  return 0;
}