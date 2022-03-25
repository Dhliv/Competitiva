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

  int n, ori; cin >> n;
  ll sum = 0, mini = LLONG_MAX, a, b;
  deque<int> staka;

  FOR(i, 0, n){
    cin >> a;
    staka.PF(a);
    sum += a;
  }

  ori = (1 << n) - 1; // all n bits on.

  FOR(i, 0, ori + 1){
    a = 0;
    b = i ^ ori;
    FOR(j, 0,  n){
      if(b & (1 << j)) a += staka[j];
    }

    if(mini > abs(sum - 2*a)) mini = abs(sum - 2*a);
  }

  cout << mini << "\n";

  return 0;
}
