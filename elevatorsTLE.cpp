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

int MAX = 1 << 20;
ll all, w[21], x, n;
vector<bool> pos(MAX);
vector<int> dp(MAX, -1);
deque<int> ch;

void td(int i, ll acum, int way){
  if(acum > x) return;
  pos[way] = 1;
  if(i == n) return;
  td(i + 1, acum + w[i], way | 1 << i);
  td(i + 1, acum, way);
  return;
}

int f(int i, int pp){ // position doesn't affect the result
  int &ans = dp[pp];
  if(ans != -1) return ans;
  if(i == ch.size()) return ans = 20;
  
  ans = f(i + 1, pp);
  ans = min(ans, 1 + f(i + 1, pp | ch[i]));

  return ans;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> x;
  FOR(i, 0, n) cin >> w[i];

  MAX = 1 << n;
  all = MAX - 1;
  dp[all] = 0;
  
  td(0, 0, 0);
  FOR(i, 1, MAX) if(pos[i]) ch.PB(i);

  cout << f(0, 0) << "\n";

  return 0;
}
