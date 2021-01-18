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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int n, d = INF, maxi = INF, aux;
  cin >> n;
  vector<int> v(n);
  
  FOR(i, 0, n){
    cin >> v[i];
  }
  
  FOR(i, 0, n - 2){
    aux = max(v[i], v[i + 2]);
    if(aux < maxi){
      d = i + 1;
      maxi = aux;
    }
  }
  
  cout << d << " " << maxi << "\n";
  
  return 0;
}