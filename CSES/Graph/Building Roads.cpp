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

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void com(int &a, int &b, vector<int> &p, vector<int> &s){
  if(s[a] < s[b]) swap(a, b);

  p[b] = a;
  s[a] += s[a];
  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y, g, xf, yf;
  cin >> n >> m;
  vector<int> p(n + 1), s(n + 1, 1);
  g = n;
  FOR(i, 1, n + 1) p[i] = i;

  FOR(i, 0, m){
    cin >> x >> y;
    xf = find(x, p);
    yf = find(y, p);

    if(xf != yf){
      g--;
      com(xf, yf, p, s);
    }
  }

  g--;
  cout << g << "\n";
  if(g){
    x = find(1, p);

    FOR(i, 2, n + 1){
      y = find(i, p);
      if(x != y){
        cout << x << " " << y << "\n";
        com(x, y, p, s);
      }
    }
  }
  
  return 0;
}
