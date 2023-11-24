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

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;

  while(t--){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int bs = 0; FOR(i, 0, n) bs += s[i] == 'B' ? 1 : 0;

    if(bs == k) cout << "0\n";
    else if(bs < k){
      cout << "1\n";
      FOR(i, 0, n){
        if(s[i] == 'B') continue;
        bs++;

        if(bs == k){
          cout << i + 1 << " " << "B\n";
          break;
        }
      }
    }else{
      cout << "1\n";
      FOR(i, 0, n){
        if(s[i] == 'A') continue;
        bs--;
        if(bs == k){
          cout << i + 1 << " A\n";
          break;
        }
      }
    }
  }

  return 0;
}