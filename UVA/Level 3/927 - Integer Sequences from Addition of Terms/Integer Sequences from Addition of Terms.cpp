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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int raiz(int k, int d){
  double ans, epsi = 1e-7, rep;
  ans = 1.0/2 + sqrt(k/(1.0*d) + 1.0/4);
  ans += epsi;
  rep = floor(ans);
  
  if(fabs(ans - rep) >= 1e-6) return (int) ans;
  else return ((int) ans) - 1;
}

ll f(int n, int grad, vector<int> &c){
  ll ans = 0, aux;
  
  FOR(i, 0, grad + 1){
    aux = c[i];
    if(aux){
      FOR(j, 0, i){
        aux *= n;
      }
    }
    ans += aux;
  }
  
  return ans;
}

int main(){
  int cases, k, d, grad, n;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> grad;
    vector<int> c(grad + 1);
    
    FOR(i, 0, grad + 1) cin >> c[i];
    cin >> d >> k;
    
    k *= 2;
    
    n = raiz(k, d);
    
    cout << f(n, grad, c) << "\n";
  }
  
  return 0;
}