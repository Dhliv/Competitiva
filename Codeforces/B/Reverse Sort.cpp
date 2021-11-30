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

  int t, n, c, u;
  string s, ord;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> s;
    c = u = 0;
    FOR(i, 0, n){
      if(s[i] == '0') c++;
      else u++;
    }

    ord = "";

    FOR(i, 0, c) ord.PB('0');
    FOR(i, 0, u) ord.PB('1');

    deque<int> ceros, unos;

    FOR(i, 0, n){
      if(s[i] != ord[i]){
        if(s[i] == '1') unos.PB(i);
        else ceros.PB(i);
      }
    }

    int ans = (unos.size() + ceros.size()) > 0 ? 1 : 0;
    cout << ans << "\n";

    if(unos.size()){
      cout << unos.size() + ceros.size();
      FOR(i, 0, unos.size()) cout << " " << unos[i] + 1;
      FOR(i, 0, ceros.size()) cout << " " << ceros[i] + 1;
      cout << "\n";
    }
  }
  
  return 0;
}