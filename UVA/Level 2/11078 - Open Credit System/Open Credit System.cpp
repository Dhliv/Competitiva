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

int main(){
  int cases, n, b, minimo, maximo;
  cin >> cases;
  
  FOR(a, 0, cases){
    pair<int, int> maxi, mini;
    mini = MP(INF, -1);
    maxi = MP(MINF, -1);
    minimo = INF;
    maximo = MINF;
    
    cin >> n;
    vector<int> data(n);
    
    FOR(i, 0, n){
      cin >> data[i];
      if(i + 1 < n and data[i] > maxi.f) maxi = MP(data[i], i);
      if(i != 0 and data[i] < mini.f) mini = MP(data[i], i);
    }
    
    if(maxi.s < mini.s) cout << maxi.f - mini.f << "\n";
    else{
      FOR(i, maxi.s + 1, n) minimo = min(minimo, data[i]);
      FORI(i, mini.s - 1, 0) maximo = max(maximo, data[i]);
      
      cout << max(maximo - mini.f, maxi.f - minimo) << "\n";
    }
  }
  
  return 0;
}