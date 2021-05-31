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

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  string a, b;
  int p, A, B;
  
  A = B = 0;
  cin >> a >> b;
  
  FOR(i, 0, a.size()) if(a[i] == 'S') A++;
  FOR(i, 0, b.size()) if(b[i] == 'S') B++;
  
  p = A*B;
  
  FOR(i, 0, p) cout << "S(";
  cout << "0";
  FOR(i, 0, p) cout << ")";
  cout << "\n";
  
  return 0;
}