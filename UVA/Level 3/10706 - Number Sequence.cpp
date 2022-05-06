#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll maxi = 1000000000000, x, pot, y, digits;
  ll potencias[12] = {1}; FOR(i, 1, 12) potencias[i] = potencias[i - 1]*10;
  vector<ll> seq; seq.PB(0);

  FOR(i, 1, maxi){
    x = (i*(i + 1))/2;
    pot = 10;

    while(i >= pot){
      y = i - pot + 1;
      x += (y*(y + 1))/2;
      pot *= 10;
    }
    if(x > maxi) break;
    seq.PB(x);
  }

  int t; cin >> t;
  ll q;

  FOR(ab, 0, t){
    cin >> q;
    digits = 1;

    auto pos = lower_bound(seq.begin(), seq.end(), q);
    --pos;
    x = q - *pos;

    while(x > digits*(potencias[digits] - potencias[digits - 1])){
      x -= digits*(potencias[digits] - potencias[digits - 1]);
      digits++;
    }

    y = (x - 1)/digits;
    y += potencias[digits - 1];

    string ans = to_string(y);
    cout << ans[(x - 1)%digits] << "\n";
  }

  return 0;
}