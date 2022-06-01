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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b, y, m; cin >> a >> b;

  if(a >= 2) {
    y = 15 + 9 + (a - 2)*4;
    m = b*4;
    y += m/12;
    m %= 12;
  }else if(a >= 1){
    y = 15;
    m = b*9;
    y += m/12;
    m %= 12;
  }else{
    m = b*15;
    y = m/12;
    m %= 12;
  }

  cout << y << " " << m << "\n";

  return 0;
}