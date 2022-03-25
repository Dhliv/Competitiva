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
  cin.open("diamond.in");
  ofstream cout("diamond.out");

  int n, k, maxi, act; cin >> n >> k;
  maxi = 0;
  vector<int> d(n);

  FOR(i, 0, n) cin >> d[i];

  sort(d.begin(), d.end());

  FOR(i, 0, n){
    act = 1;
    FOR(j, i + 1, n){
      if(d[j] > d[i] + k) break;
      act++;
    }

    maxi = max(maxi, act);
  }

  cout << maxi << "\n";
  
  return 0;
}
