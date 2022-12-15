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
const int mod = 1073741824;

vector<int> primes;

ll calc(ll a){
  ll res = 1, aux;

  for(int i = 0; i < primes.size() and a != 1; i++){
    aux = 1;
    while(a%primes[i] == 0){
      aux++;
      a /= primes[i];
    }

    res *= aux;
  }

  return res%mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  const int MAX = 1000000;
  vector<int> prime(MAX, 0);
  for(int i = 2; i < MAX; i += 2) prime[i] = true;
  primes.assign(0, {});

  primes.PB(2);
  for(int i = 3; i < MAX; i += 2){
    if(prime[i]) continue;
    primes.PB(i);
    for(int j = i; j < MAX; j += i) prime[j] = true;
  }

  int a, b, c; cin >> a >> b >> c;
  ll res = 0;

  FOR(i, 1, a + 1){
    FOR(j, 1, b + 1){
      FOR(k, 1, c + 1){
        res = (res + calc(i*j*k))%mod;
      }
    }
  }

  cout << res << "\n";

  return 0;
}