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

  deque<int> q, ans;
  FOR(i, 1, 10010) if(i%3) q.PB(i);

  FOR(i, 0, q.size()) if(q[i]%10 != 3) ans.PB(q[i]);

  int n, t;
  cin >> t;
  FOR(ab, 0, t){
    cin >> n;
    n--;
    cout << ans[n] << "\n";
  }

  return 0;
}