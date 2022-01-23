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

  int n; cin >> n;
  int a, b, x, y;
  a = b = 0;
  vector<int> ans(n);

  FOR(i, 0, n){
    cin >> x >> y;
    if(abs(a + x - b) <= 500){
      a += x;
      ans[i] = 1;
    }
    else {
      b += y;
      ans[i] = 2;
    }
  }

  if(abs(a - b) > 500)  cout << "-1\n";
  else{
    FOR(i, 0, n) cout << (ans[i] == 1 ? 'A' : 'G');
    cout << "\n";
  }
  
  return 0;
}
