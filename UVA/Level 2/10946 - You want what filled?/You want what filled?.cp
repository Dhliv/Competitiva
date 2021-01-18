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

int n, m;

int f(int i, int j, char &k, vector<string> &t){
  int ans = 1;
  t[i][j] = '.';
  
  if(i - 1 >= 0 and t[i - 1][j] == k) ans += f(i - 1, j, k, t);
  if(j - 1 >= 0 and t[i][j - 1] == k) ans += f(i, j - 1, k, t);
  if(j + 1 < m and t[i][j + 1] == k) ans += f(i, j + 1, k, t);
  if(i + 1 < n and t[i + 1][j] == k) ans += f(i + 1, j, k, t);
  
  return ans;
}

int main(){
  int d, cont = 1;
  char k;
  
  while(cin >> n >> m, n + m){
    cout << "Problem " << cont++ << ":\n";
    vector<string> t(n);
    
    FOR(i, 0, n) cin >> t[i];
    
    priority_queue<pair<int, int> > q;
    FOR(i, 0, n){
      FOR(j, 0, m){
        k = t[i][j];
        if(k - 'A' >= 0 and k - 'A' <= 25){
          d = f(i, j, k, t);
          q.push(MP(d, -k));
        }
      }
    }
    
    while(!q.empty()){
      d = q.top().f;
      k = abs(q.top().s);
      q.pop();
      
      cout << k << " " << d << "\n";
    }
  }
  
  return 0;
}