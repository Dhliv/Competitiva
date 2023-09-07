#include <bits/stdc++.h>
#define INF INT_MAX
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

  int n;
  const int MAX = 90;
  vector<ll> fib(MAX);
  fib[0] = fib[1] = 1;
  FOR(i, 2, MAX) fib[i] = fib[i - 1] + fib[i - 2];

  while(cin >> n, n){
    cout << fib[n - 1] << "\n";
  }
 
  return 0;
}