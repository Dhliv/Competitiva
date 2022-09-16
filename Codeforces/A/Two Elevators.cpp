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

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int a, b, c, a1, a2;

  FOR(i, 0, t){
    cin >> a >> b >> c;

    a1 = a - 1;
    a2 = abs(c - b) + c - 1;

    if(a1 < a2) cout << "1\n";
    else if(a2 < a1) cout << "2\n";
    else cout << "3\n";
  }

  return 0;
}