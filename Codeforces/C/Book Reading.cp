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
#define MAX 1000000

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ll cyc, n, m, q, ans, x, sum, suma, completos, sobra;
  cin >> q;
  
  FOR(ab, 0, q){
    cin >> n >> m;
    vector<int> orden;
    set<int> ciclo;
    
    sum = m%10;
    x = sum;
    suma = 0;
    while(true){
      if(ciclo.find(x) != ciclo.end()) break;
      orden.PB(x);
      ciclo.insert(x);
      suma += x;
      x += sum;
      x %= 10;
    }
    
    ans = 0;
    cyc = ciclo.size();
    x = n/m;
    sobra = x%cyc;
    completos = x - sobra;
    ans += (completos/cyc)*suma;
    
    FOR(i, 0, sobra) ans += orden[i];
    
    cout << ans << "\n";
  }

  return 0;
}