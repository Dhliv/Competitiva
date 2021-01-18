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
  int fx = p[x];
  if(fx == x) return x;
  else return p[x] = find(fx, p);
}

int main(){
  int c, r, x, y, maxi, fx, fy, cont;
  string a, b;
  
  while(cin >> c >> r, c){
    vector<int> sum(c, 1), p(c);
    map<string, int> id;
    cont = 0;
    
    FOR(i, 0, c){
      cin >> a;
      p[i] = i;
      id.insert(MP(a, cont++));
    }
    
    maxi = 1;
    FOR(i, 0, r){
      cin >> a >> b;
      x = id[a], y = id[b];
      fx = find(x, p), fy = find(y, p);
      if(fx != fy){
        p[fx] = fy;
        sum[fy] += sum[fx];
        maxi = max(maxi, sum[fy]);
      }
    }
    
    cout << maxi << "\n";
  }
  
  return 0;
}