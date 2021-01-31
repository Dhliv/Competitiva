#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ld long double
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
  int cases;
  ld c, k, s, g;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> k >> s >> g;
    c = (k/2 - s + sqrt((s - k/2)*(s - k/2) + 2*k*g))/k + 1e-6;
    cout << (int)ceil(c) << "\n";
  }
  
  return 0;
}