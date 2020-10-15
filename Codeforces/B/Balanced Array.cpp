#include <bits/stdc++.h>
#define LINF LLONG_MAX
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int t, n, cont;
  cin >> t;
  
  FOR(a, 0, t){
    cin >> n;
    if(n/2 % 2) cout << "NO\n";
    else{
      cout << "YES\n";
      cont = 0;
      vector<int> fi(n/2), se(n/2);
      set<int> all;
      
      for(int i = 2; i <= n; i += 2) fi[i/2 - 1] = i;
      
      for(int i = 1; i < pow(10, 9) + 1; i += 2){
        if(cont >= n/2) break;
        if(all.find(i) == all.end()){
          all.insert(i);
          se[cont] = i;
          se[cont + 1] = fi[cont + 1] + (fi[cont] - se[cont]);
          all.insert(se[cont + 1]);
          cont += 2;
        }
      }
      
      FOR(i, 0, n/2) cout << fi[i] << " ";
      
      FOR(i, 0, n/2) cout << se[i] << " ";
      cout << "\n";
    }
  }
  
  return 0;
}