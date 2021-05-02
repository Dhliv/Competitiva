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


int pos[10], ans, ax, num[10], fr, mat[10][10];


void f(int i){
  if(i == 10){
    ax = num[fr];
    FOR(j, 0, 10){
      FOR(k, j, 10){
        ax += abs(num[j] - num[k])*mat[j][k];
      }
    }
    
    ans = min(ans, ax);
  }else{
    FOR(j, 0, 10){
      if(pos[j] == -1){
        pos[j] = i;
        num[i] = j;
        f(i + 1);
        pos[j] = -1;
      }
    }
  }
  
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string a;
  int x, y;
  cin >> a;
  memset(mat, 0, sizeof(mat));
  
  fr = a[0] - '0';
  FOR(i, 1, a.size()){
    x = a[i - 1] - '0';
    y = a[i] - '0';
    if(x > y) swap(x, y);
    mat[x][y]++;
  }
  
  memset(pos, -1, sizeof(pos));
  ans = INF;
  f(0);
  cout << ans + a.size() << "\n";

  return 0;
}