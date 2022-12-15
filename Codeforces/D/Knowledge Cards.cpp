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

  int t; cin >> t;
  ll n, m, k, out, mini, r, act;

  while(t--){
    cin >> n >> m >> k;

    vector<int> isOut(k + 1), p(k); FOR(i, 0, k) cin >> p[i];
    r = 0; act = k;
    out = 0;

    bool able = true;
    while(able and act != 0){
      while(!isOut[act]){
        out++;
        isOut[p[r++]] = 1;
      }

      if(n*m - 2 - out + 1 >= 2){
        out--;
        act--;
      }else able = false;
    }

    cout << (able ? "YA" : "TIDAK") << "\n";
  }

  return 0;
}