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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main() {
  int n;
  string a[3] ={"Either", "Odd", "Even"};
  cin>>n;
  if(n == 1) cout << a[0] << endl;
  if(n == 2) cout << a[1] << endl;
  if(n == 3) cout << a[0] << endl;
  if(n == 4) cout << a[2] << endl;
  if(n == 5) cout << a[0] << endl;
  if(n == 6) cout << a[1] << endl;
  if(n == 7) cout << a[0] << endl;
  if(n == 8) cout << a[2] << endl;
  if(n == 9) cout << a[0] << endl;
  if(n == 10) cout << a[1] << endl;
  
  return 0;
}