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
  ll a, b, k, ini;
  cin >> a >> b >> k;
  int l = 1000000;
  vector<int> prims, pri(l), range(b - a + 1), nums;
  prims.PB(2);
  ini = a/2;
  ini *= 2;
  
  for(int i = ini - a; i <= b - a; i += 2){
    if(i >= 0){
      range[i] = 1;
      nums.PB(2);
    }
  }
  
  for(int i = 3; i < l; i += 2){
    if(!pri[i]){
      prims.PB(i);
      for(int j = i; j < l; j += i) pri[j] = 1;
      
      ini = a/i;
      ini *= i;
      
      for(int j = ini - a; j <= b - a; j += i){
        if(j >= 0){
          if(!range[j]){
            range[j] = 1;
            nums.PB(i);
          }
        }
      }
    }
  }
  
  ll sum = 0;
  
  FOR(i, 0, k){
    sum += nums[i];
  }
  
  cout << sum << "\n";
  
  return 0;
}