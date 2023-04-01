#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846

using namespace std;
 
const ld EPSILON = 0.0000001;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, fl, sl, fe, se, l, r, x;
  bool turn;

  while(t--){
    cin >> n;
    l = 1;
    r = n;
    fl = sl = fe = se = 0;
    FOR(i, 0, n){
      cin >> x;
      if(l != x and r != x){
        fl++; sl++;
        l++; r--;
        continue;
      }

      if(l == x and r != x){
        sl++; se++;
        l++; r--;
        continue;
      }

      if(r == x and l != x){
        fl++; fe++;
        l++; r--;
        continue;
      }

      l++; r--;
    }

    turn = 0;
    while(true){
      if(fl == 0 and turn == 0){
        cout << "First";
        break;
      }

      if(sl == 0 and turn == 1){
        cout << "Second";
        break;
      }

      if(se == 0 and fe == 0 and fl == sl){
        cout << "Tie";
        break;
      }

      if(!turn){
        if(fe){
          fl--; fe--;
        }else{
          fl--; sl--;
        }
      }else{
        if(se){
          sl--; se--;
        }else{
          sl--; fl--;
        }
      }

      turn = 1 - turn;
    }

    cout << "\n";
  }

  return 0;
}