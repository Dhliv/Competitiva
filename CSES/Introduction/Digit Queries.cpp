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

ll k;

bool able(ll &x, bool print = false){
  ll digits = 0;
  ll l = 1, r = 10, i = 1;

  while(x >= r){
    digits += i*(r - l);
    r *= 10;
    l *= 10;
    i++;
  }

  if(print){
    string num = to_string(x);
    ll aux = digits + i*(x - l);
    ll aux2 = k - aux;
    cout << num[aux2 - 1] << "\n";
  }

  digits += i*(x - l + 1);

  return digits >= k;
}

ll bs(){
  ll l = 1, r = 1000000000000000000, m;

  while(l <= r){
    m = (l + r)/2;

    if(able(m)) r = m - 1;
    else l = m + 1;
  }

  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int q; cin >> q;

  FOR(i, 0, q){
    cin >> k;
    ll num = bs();
    able(num, true);
  }

  return 0;
}