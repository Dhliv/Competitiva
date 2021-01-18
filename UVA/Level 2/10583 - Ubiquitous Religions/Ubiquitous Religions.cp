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

vector<int> p;

int find(int x){
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

void com(int a, int b){
  p[a] = b;
  return;
}

int main(){
  int n, m, x, y, ans, a, b, cont = 1;
  
  while(cin >> n >> m, n + m){
    cout << "Case " << cont++ << ": ";
    p.resize(n + 1);
    FOR(i, 1, n + 1) p[i] = i;
    ans = n;
    
    FOR(i, 0, m){
      cin >> x >> y;
      a = find(x), b = find(y);
      if(a != b){
        ans--;
        com(a, b);
      }
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}