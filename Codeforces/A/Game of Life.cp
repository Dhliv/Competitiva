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
  
  int t, n, m, v, x;
  string a;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n >> m >> a;
    deque<int> q, nxt;
    vector<int> al(n, 100);
    
    FOR(i, 1, a.size() - 1){
      if(a[i] == '0'){
        v = (a[i - 1] - '0') + (a[i + 1] - '0');
        al[i] = v;
      }
    }
    
    if(a[0] == '0') al[0] = a[1] - '0';
    if(a[n - 1] == '0') al[n - 1] = a[n - 2] - '0';
    
    FOR(i, 0, n) if(al[i] == 1) q.PB(i);
    
    while(!q.empty() and m){
      while(!q.empty()){
        x = q.F();
        q.P_F();
        
        if(x > 0){
          al[x - 1]++;
          if(al[x - 1] == 1) nxt.PB(x - 1);
        }
        if(x + 1 < n){
          al[x + 1]++;
          if(al[x + 1] == 1) nxt.PB(x + 1);
        }
        
        a[x] = '1';
      }
      m--;
      
      while(!nxt.empty()){
        x = nxt.F();
        nxt.P_F();
        if(al[x] == 1) q.PB(x);
      }
    }
    
    cout << a << "\n";
  }
  
  return 0;
}