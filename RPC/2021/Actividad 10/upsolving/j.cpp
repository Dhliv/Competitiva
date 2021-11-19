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

  int n, q, w, id, ans;

  while(cin >> n >> q){
    vector<int> s(n + 1);
    id = 0;
    cin >> w;
    s[1] = 1;

    FOR(i, 2, n + 1){
      cin >> w;
      s[i] = s[i - 1] + w;
    }

    FOR(i, 0, q){
      cin >> w;
      ans = upper_bound(s.begin(), s.end(), w) - s.begin() - 1;
      if(id++) cout << " ";
      cout << ans;
    }
    cout << "\n";
  }

  return 0;
}