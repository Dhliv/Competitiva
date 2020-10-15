#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, par, impar, resta, n, aux;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    par = impar = resta = 0;
    vector<int> v(n);
    
    FOR(i, 0, n){
      cin >> v[i];
      if(v[i]%2)
        impar++;
      else
        par++;
    }
    
    sort(v.begin(), v.end());
    FOR(i, 1, n){
      if(abs(v[i] - v[i-1]) == 1){
        resta++;
        break;
      }
    }
    
    if(par%2 and resta)
      cout << "YES\n";
    else if(par%2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  
  return 0;
}