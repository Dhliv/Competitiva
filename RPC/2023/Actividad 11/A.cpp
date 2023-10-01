#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  bool div = 0, has = 0;

  div = n%7 == 0;

  while(n){
    if(n%10 == 7) has = true;
    n /= 10;
  }

  if(div and has) cout << "3\n";
  else if(has and !div) cout << "2\n";
  else if(div and !has) cout << "1\n";
  else cout << "0\n";

  return 0;
}