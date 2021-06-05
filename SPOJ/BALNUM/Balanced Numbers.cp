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

map<vector<int>, ll> dp[19][2][2][2];

ll f(int i, bool f1, bool f2, bool e, string &a, string &b, vector<int> &v){
  if(i == b.size()){
    bool able = true;
    FOR(j, 0, 10){
      if(v[j] > 0){
        if(j%2){
          able &= (1 - v[j]%2);
        }else{
          able &= v[j]%2;
        }
      }
    }
    
    if(able) return 1;
    return 0;
  }
  
  ll ans = 0;
  auto fi = dp[i][f1][f2][e].find(v);
  if(fi != dp[i][f1][f2][e].end()) return fi->s;
  
  int nf1, nf2, ne, lim, low;
  lim = (f2 == 1) ? 9 : (b[i] - '0');
  low = (f1 == 1) ? 0 : (a[i] - '0');
  ans = 0;
  
  FOR(j, low, lim + 1){
    nf1 = f1;
    nf2 = f2;
    ne = e;
    if(!f1 and j > low) nf1 = 1;
    if(!f2 and j < lim) nf2 = 1;
    if(!e and j > 0) ne = 1;
    
    if(ne){
      v[j]++;
      ans += f(i + 1, nf1, nf2, ne, a, b, v);
      v[j]--;
    }else{
      ans += f(i + 1, nf1, nf2, ne, a, b, v);
    }
  }
  
  dp[i][f1][f2][e].insert(MP(v, ans));
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t;
  string a, b, ax;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> a >> b;
    ax = "";
    FOR(i, 0, b.size() - a.size()) ax.PB('0');
    a = ax + a;
    
    vector<int> p(10, 0);
    map<vector<int>, ll> empty;
    
    FOR(i, 0, 19){
      FOR(f1, 0, 2){
        FOR(f2, 0, 2){
          FOR(e, 0, 2) dp[i][f1][f2][e] = empty;
        }
      }
    }
    
    cout << f(0, 0, 0, 0, a, b, p) << "\n";
  }
  
  return 0;
}