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
#define dat pair<int, pair<int, int> >
#define MAX 1000001

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int t, a, ans, ax;
  bool dp[MAX];
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> a;
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i < MAX; i += 2020){
      for(int j = 2021 + i; j < MAX; j += 2021) dp[j] = 1;
    }
    
    for(int i = 0; i < MAX; i += 2021){
      for(int j = 2020 + i; j < MAX; j += 2020) dp[j] = 1;
    }
    
    if(dp[a]) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}