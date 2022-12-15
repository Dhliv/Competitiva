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
  int pares, impares, l, r;

  pares = n/2;
  impares = n - pares;

  if(impares & 1) cout << "NO\n";
  else{
    cout << "YES\n";
    vector<int> a, b;

    l = 1; r = n & 1 ? n : n - 1;
    while(impares > 2){
      FOR(i, 0, 2){
        if(i){
          a.PB(l);
          a.PB(r);
        }else{
          b.PB(l);
          b.PB(r);
        }

        l += 2;
        r -= 2;
        impares -= 2;
      }
    }

    if(impares and !(pares & 1)){
      a.PB(l);
      b.PB(r);
      a.PB(4);
      b.PB(2);

      l = 6;
      r = n;
    }else if(impares){
      a.PB(l);
      b.PB(r);
      a.PB(2);

      l = 4;
      r = n & 1 ? n - 1 : n;
    }else if(pares & 1){
      a.PB(2);
      r = n & 1 ? n - 1 : n;
      b.PB(r);
      a.PB(r - 2);
      r -= 4;
      l = 4;
    }else{
      l = 2;
      r = n & 1 ? n - 1 : n;
    }

    while(l < r){
      FOR(i, 0, 2){
        if(i){
          a.PB(l);
          a.PB(r);
        }else{
          b.PB(l);
          b.PB(r);
        }

        l += 2;
        r -= 2;
      }
    }

    cout << a.size() << "\n" << a.F();
    FOR(i, 1, a.size()) cout << " " << a[i];
    cout << "\n" << b.size() << "\n" << b.F();
    FOR(i, 1, b.size()) cout << " " << b[i];
    cout << "\n";
  }

  return 0;
}