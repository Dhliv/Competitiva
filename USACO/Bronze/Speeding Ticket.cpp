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
  cin.open("speeding.in");
  ofstream cout("speeding.out");

  int road[101], cow[101];
  int n, m; cin >> n >> m;
  int x, y, act;

  act = 1;
  FOR(i, 0, n){
    cin >> x >> y;
    FOR(j, 0, x) road[act++] = y;
  }

  act = 1;
  FOR(i, 0, m){
    cin >> x >> y;
    FOR(j, 0, x) cow[act++] = y;
  }

  int maxi = 0;
  FOR(i, 1, 101){
    maxi = max(maxi, cow[i] - road[i]);
  }

  cout << maxi << "\n";

  return 0;
}
