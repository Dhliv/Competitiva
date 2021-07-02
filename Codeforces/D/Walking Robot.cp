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
  
  int n, am, bm, a, b, d = 0, id = 0, x;
  cin >> n >> bm >> am;
  b = bm;
  a = am;
  
  while(id < n and (a + b)){
    cin >> x;
    
    if(x == 0){
      if(a){
        a--;
        d++;
      }else{
        b--;
        d++;
      }
    }else{
      if(a < am and b){
        a++;
        b--;
        d++;
      }else if(a == am or a){
        a--;
        d++;
      }else{
        b--;
        d++;
      }
    }
    
    id++;
  }
  
  cout << d << "\n";
  
  return 0;
}