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

  int x, n, sum = 0; cin >> n;
  vector<int> imp;

  FOR(i, 0, n){
    cin >> x;
    if(x & 1) imp.PB(x);
    else sum += x;
  }

  if(!imp.empty()){
    sort(imp.begin(), imp.end());

    FOR(i, 0, imp.size()) sum += imp[i];

    if(!(imp.size() & 1)) sum -= imp[0];

    cout << sum << "\n";
  }else cout << "0\n";
  
  return 0;
}
