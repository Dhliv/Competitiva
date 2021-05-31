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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ld epsilon = 1e-6, uno = 1.0;
  cout.precision(4);
  
  int n, k, mini, maxi, sum, x;
  cin >> n >> k;
  
  sum = 0;
  FOR(i, 0, k){
    cin >> x;
    sum += x;
  }
  
  mini = sum - 3*(n - k);
  maxi = sum + 3*(n - k);
  
  cout << fixed << ((mini*uno)/(n*uno) + epsilon) << " " << ((maxi*uno)/(n*uno) + epsilon) << "\n";
  
  return 0;
}