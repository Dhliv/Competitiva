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
  int l = 1e6 + 1;
  vector<bool> is(l);
  vector<int> prims;
  
  ll n, t, s, c, p, ns = 0, nc = 0, np = 0, added, cont = 0, left;
  cin >> n >> t >> s >> p >> c;
  bool pr = false;
  
  if(t == 0) cout << s << " " << p << " " << c << "\n";
  else{
    FOR(i, 2, n + 1){
      if(!is[i]){
        for(int j = i; j < n + 1; j += i) is[j] = true;
        prims.PB(i);
      }
    }
    
    added = t/n;
    
    if(added){
      np += added*prims.size();
      nc += added*(n - (prims.size() + 1));
    }
    
    if(s != 1){
      FOR(i, 0, prims.size()){
        if(prims[i] == s) pr = true;
      }
      
      if(pr) np--;
      else nc--;
    }
    
    t %= n;
    
    if((s - t) <= 0){
      FOR(i, 0, prims.size()){
        if(prims[i] > s){
          np += i;
          nc += (s - (i + 1));
          break;
        }
        
        if(i + 1 == prims.size()){
          np += i + 1;
          nc += (s - (i + 2));
        }
      }
      
      left = n - (t - s);
      
      FORI(i, prims.size() - 1, 0){
        if(prims[i] < left){
          np += cont;
          nc += ((n - left + 1) - cont);
          break;
        }
        
        if(i == 0){
          np += cont + 1;
          nc += (1 + (n - left) - (cont + 1));
        }
        cont++;
      }
    }else{
      left = s - t;
      
      FOR(i, 0, prims.size()){
        if(prims[i] >= left and prims[i] <= s) cont++;
      }
      
      np += cont;
      nc += (1 + (s - left) - cont);
      
      if(left == 1) nc--;
    }
    
    nc %= n;
    np %= n;
    
    ns = s - t;
    np = p - np;
    nc = c + nc;
    
    if(ns <= 0) ns += n;
    if(np <= 0) np += n;
    if(nc > n or nc == 0){
      added = nc%n;
      if(added) nc = added;
      else nc = n;
    }
    
    cout << ns << " " << np << " " << nc << "\n";
  }

  return 0;
}