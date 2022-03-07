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
  vector<int> cnt(3), cows(n); // 0 -> A| 1 -> F| 2 -> I
  int x;
  string s; cin >> s;

  FOR(i, 0, s.size()){
    x = 0;
    if(s[i] == 'F') x = 1;
    else if(s[i] == 'I') x = 2;
    cows[i] = x;
    cnt[x]++;
  }

  int ans = 0;

  FOR(i, 0, n){
    x = cows[i];

    if(x == 0){
      if(cnt[2] == 0) ans++;
    }else if(x == 2){
      if(cnt[x] - 1 == 0) ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}
