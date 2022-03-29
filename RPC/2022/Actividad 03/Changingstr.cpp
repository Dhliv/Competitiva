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

  string a; cin >> a;
  int pu, pf;
  FOR(i, 0, a.size()){
    if(a[i] == 'U'){
      pu = i + 1;
      break;
    }
    a[i] = '-';
  }

  FORI(i, a.size() - 1, 0){
    if(a[i] == 'F'){
      pf = i;
      break;
    }
    a[i] = '-';
  }

  FOR(i, pu, pf) a[i] = 'C';

  cout << a << "\n";

  return 0;
}
