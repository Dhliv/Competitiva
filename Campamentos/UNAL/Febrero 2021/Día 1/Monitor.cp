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

struct st{
  int l, r, m, maxi;
  st *left, *right;
  
  st(int l, int r, vector<int> &d){
    this->l = l;
    this->r = r;
    
    if(l == r) maxi = d[l];
    else{
      m = (l + r)/2;
      left = new st(l, m, d);
      right = new st(m + 1, r, d);
      maxi = max(left->maxi, right->maxi);
    }
  }
  
  int get(int &i, int &j){
    if(i > r or j < l) return -1;
    if(i <= l and r <= j) return maxi;
    return max(left->get(i, j), right->get(i, j));
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int n, m, k, q, mini, x, y, dead;
  cin >> n >> m >> k >> q;
  
  vector<vector<int> > dp(n, vector<int> (m)), d(n, vector<int> (m)), t(m, vector<int> (n, -1));
  
  FOR(i, 0, q){
    cin >> x >> y >> dead;
    x--; y--;
    d[x][y] = 1;
    t[y][x] = dead;
  }
  
  FOR(i, 0, m) dp[0][i] = d[0][i];
  
  FOR(i, 1, n){
    FOR(j, 0, m){
      dp[i][j] = d[i][j];
      if(dp[i][j] and j){
        dp[i][j] += min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
      }
    }
  }
  
  deque<st> trU, trL;
  FOR(i, 0, m){
    st ax(0, n - 1, t[i]);
    trU.PB(ax);
  }
  
  vector<vector<int> > dpM(n, vector<int> (m, -1));
  FOR(i, k - 1, n){
    FOR(j, 0, m){
      x = i - k + 1;
      y = i;
      dpM[i][j] = trU[j].get(x, y);
    }
  }
  
  FOR(i, 0, n){
    st ax(0, m - 1, dpM[i]);
    trL.PB(ax);
  }
  
  mini = INF;
  FOR(i, 0, n){
    FOR(j, 0, m){
      if(dp[i][j] >= k){
        x = j - k + 1;
        y = j;
        mini = min(mini, trL[i].get(x, y));
      }
    }
  }
  
  if(mini != INF) cout << mini << "\n";
  else cout << "-1\n";
  
  return 0;
}