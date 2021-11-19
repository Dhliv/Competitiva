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

  set<int> prs;
  vector<bool> s(400);

  FOR(i, 2, 400){
    if(s[i]) continue;
    for(int j = i; j < 400; j += i) s[j] = 1;
    prs.insert(i);
  }

  int t, n, ans;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    ans = 0;

    for(auto x : prs){
      if(x > n/2) break;
      if(prs.find(n - x) != prs.end()) ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}