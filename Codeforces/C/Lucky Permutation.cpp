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

  int n; cin >> n;

  deque<int> p(n + 1);
  int l = 1, r = n;

  while(r - l >= 3){
    p[l + 1] = r;
    p[l] = l + 1;
    p[r - 1] = l;
    p[r] = r - 1;
    r -= 2;
    l += 2;
  }

  int ans = r - l;
  bool able = 0;
  if(ans == 0){
    able = 1;
    p[l] = l;
  }else if(ans == 1) able = 0;
  else if(ans == 2) able = 0;
  else able = 1;

  if(able){
    FOR(i, 1, n + 1) cout << p[i] << " ";
  }else cout << "-1";

  cout << "\n";
  
  return 0;
}