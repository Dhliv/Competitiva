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

  int t; cin >> t;
  int n, l, r, f;
  bool able;
  int p[500];

  FOR(ab, 0, t){
    cin >> n;
    f = 1;
    l = 0;
    r = n - 1;
    able = false;

    FOR(i, 0, n){
      cin >> p[i];
      if(!able and f != p[i]){
        able = 1;
        l = i;
      }else if(able and f == p[i]){
        r = i;
      }else if(!able and f == p[i]) f++;
    }

    if(able){
      FOR(i, 0, l) cout << p[i] << " ";
      FORI(i, r, l) cout << p[i] << " ";
      FOR(i, r + 1, n) cout << p[i] << " ";
    }else FOR(i, 0, n) cout << p[i] << " ";
    cout << "\n";
  }

  return 0;
}
