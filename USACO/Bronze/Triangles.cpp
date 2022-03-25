#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

int calc(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c){
  if(a.s == b.s and b.f == c.f) return (abs(a.f - b.f)*abs(b.s - c.s));
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("triangles.in");
  ofstream cout("triangles.out");

  int n; cin >> n;
  int maxi = 0;
  vector<pair<int, int> > p(n);

  FOR(i, 0, n) cin >> p[i].f >> p[i].s;

  FOR(i, 0, n){
    FOR(j, 0, n){
      if(i == j) continue;
      FOR(k, 0, n){
        if(k == i or k == j) continue;
        maxi = max(maxi, calc(p[i], p[j], p[k]));
      }
    }
  }

  cout << maxi << "\n";

  return 0;
}
