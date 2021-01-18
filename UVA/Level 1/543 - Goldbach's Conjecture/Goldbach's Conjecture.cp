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
  int l = 1e6;
  set<int> prims;
  auto it = prims.begin();
  vector<bool> p(l);
  
  FOR(i, 2, l){
    if(!p[i]){
      prims.insert(it, i);
      for(int j = 2*i; j < l; j += i) p[j] = true;
      it++;
    }
  }
  
  int n, b, maxi, adef, bdef, x;
  while(cin >> n, n){
    maxi = MINF;
    auto it = prims.begin();
    auto fin = prims.lower_bound(n);
    
    for(it; it != fin; it++){
      x = *it;
      b = *(prims.lower_bound(n - x));
      if(x + b == n and b - x > maxi){
        maxi = b - x;
        adef = x;
        bdef = b;
        break;
      }
    }
    
    cout << n << " = " << adef << " + " << bdef << "\n";
  }
  
  return 0;
}