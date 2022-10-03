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
  int n;

  FOR(ab, 0, t){
    cin >> n;

    if(n == 1) cout << "1\n";
    else if(n == 2) cout << "2 1\n";
    else if(n == 3) cout << "3 1 2\n";
    else{
      if(n & 1){
        FORI(i, n - 2, 4) cout << i << " ";
        cout << "2 3 1 " << n - 1 << " " << n << "\n";
      }else{
        FORI(i, n - 2, 1) cout << i << " ";
        cout << n - 1 << " " << n << "\n";
      }
    }
  }

  return 0;
}