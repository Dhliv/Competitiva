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

bool comp(pair<int, int> &a, pair<int, int> &b){
  int x, y;
  x = a.f*b.s;
  y = a.s*b.f;
  
  return x < y;
}

int main(){
  ios_base::sync_with_stdio(false);
  int n, k, a, b, mat[1001][1001], x;
  
  while(cin >> n >> k){
    FOR(i, 1, n + 1){
      FOR(j, 1, n + 1){
        mat[i][j] = 0;
      }
    }
    
    deque<pair<int, int> > q;
    
    FOR(i, 1, n + 1){
      FOR(j, 1, n + 1){
        a = i;
        b = j;
        x = __gcd(a, b);
        a /= x;
        b /= x;
        
        if(mat[a][b] == 0) q.PB(MP(a, b));
        mat[a][b] = 1;
      }
    }
    
    sort(q.begin(), q.end(), comp);
    
    k--;
    cout << q[k].f << "/" << q[k].s << "\n";
  }
  return 0;
}