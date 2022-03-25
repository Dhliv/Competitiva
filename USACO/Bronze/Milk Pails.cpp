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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("pails.in");
  ofstream cout("pails.out");

  int x, y, m; cin >> x >> y >> m;
  int maxi = 0, act;

  FOR(i, 0, m/x){
    act = i*x;
    act += y*((m - act)/y);
    maxi = max(maxi, act);
  }

  FOR(i, 0, m/y){
    act = i*y;
    act += x*((m - act)/x);
    maxi = max(maxi, act);
  }

  cout << maxi << "\n";
  
  return 0;
}
