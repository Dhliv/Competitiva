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

  string a, b; cin >> a >> b;
  int as = 0, bs = 0;
  FOR(i, 0, a.size()) as += (a[i] - '0');
  FOR(i, 0, b.size()) bs += (b[i] - '0');

  as *= a.size();
  bs *= b.size();
  if(as == bs) cout << "0\n";
  else if (as < bs) cout << "2\n";
  else cout << "1\n";

  return 0;
}
