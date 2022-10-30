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

  int par, impar, aux;
  par = 1;
  impar = 0;
  const int mod = 1000007;

  int m; cin >> m;
  if(m <= 2) cout << "1\n";
  else{
    FOR(i, 2, m){
      aux = impar + par;
      impar = par%mod;
      par = aux%mod;
    }

    cout << (par + impar)%mod << "\n";
  }
  
  return 0;
}