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

  int t, n, q, y; cin >> t;
  ll par, impar, ni, np, x;

  while(t--){
    cin >> n >> q;
    par = impar = ni = np = 0;

    FOR(i, 0, n){
      cin >> x;
      if(x & 1){
        impar += x;
        ni++;
      }else{
        par += x;
        np++;
      }
    }

    FOR(i, 0, q){
      cin >> y >> x;

      if(y){ // impar
        if(x & 1){
          par += impar + ni*x;
          np = n;
          impar = ni = 0;
        }else impar += ni*x;
      }else{ // par
        if(x & 1){
          impar += par + np*x;
          par = np = 0;
          ni = n;
        }else par += np*x;
      }

      cout << par + impar << "\n";
    }
  }

  return 0;
}