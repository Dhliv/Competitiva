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
  cin.open("shuffle.in");
  ofstream cout("shuffle.out");

  int n, x; cin >> n;
  vector<int> a(n + 1), ori(n + 1), aux(n + 1);

  FOR(i, 1, n + 1) cin >> a[i];
  FOR(i, 1, n + 1) ori[i] = i;

  FOR(ab, 0, 3){
    FOR(i, 1, n + 1){
      aux[a[i]] = ori[i];
    }

    aux.swap(ori);
  }

  FOR(i, 1, n + 1){
    cin >> x;
    aux[ori[i]] = x;
  }

  FOR(i, 1, n + 1) cout << aux[i] << "\n";
  
  return 0;
}
