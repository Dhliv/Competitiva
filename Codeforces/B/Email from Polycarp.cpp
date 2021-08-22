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

  int n; cin >> n;
  string x, y;
  char last;

  FOR(ab, 0, n){
    cin >> x >> y;
    deque<char> a, b;

    FOR(i, 0, x.size()) a.PB(x[i]);
    FOR(i, 0, y.size()) b.PB(y[i]);

    last = '#';
    while(!a.empty() and b.size() >= a.size()){
      if(a.F() == b.F()){
        last = b.F();
        a.P_F();
        b.P_F();
      }else if(last == b.F()){
        while(!b.empty() and last == b.F()) b.P_F();
      }else break;
    }

    while(!b.empty() and last == b.F()) b.P_F();

    if(a.empty() and b.empty()) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}
