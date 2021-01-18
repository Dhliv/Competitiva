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

int sum[30004], p[30004];

int find(int x){
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

void com(int a, int b){
  p[a] = b;
  sum[b] += sum[a];
}

int main(){
  int cases, n, m, x, y, maxi, a, b;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n >> m;
    FOR(i, 1, n + 1) p[i] = i, sum[i] = 1;
    
    maxi = 1;
    FOR(i, 0, m){
      cin >> x >> y;
      a = find(x), b = find(y);
      if(a != b){
        com(a, b);
        maxi = max(maxi, sum[b]);
      }
    }
    cout << maxi << "\n";
  }
  
  return 0;
}