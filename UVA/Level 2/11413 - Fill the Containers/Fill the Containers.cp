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

int maxi = MINF;

bool check(vector<int> &v, int n, int m, int cota){
  int sum = 0, cont = 0;
  
  if(maxi > cota) return false;
  
  FOR(i, 0, n){
    sum += v[i];
    if(sum > cota){
      cont++;
      sum = 0;
      i--;
    }
    if(cont >= m) return false;
  }
  
  return true;
}

int search(int n, vector<int> &v, int m, int sum){
  int low = 1, high = sum, mid;
  bool able;
  
  while(low <= high){
    mid = (low + high)/2;
    
    if(check(v, n, m, mid)) high = mid - 1;
    else low = mid + 1;
  }
  
  return low;
}

int main(){
  int n, m, sum, x, y;
  
  while(cin >> n >> m){
    sum = 0;
    maxi = MINF;
    vector<int> v(n);
    
    FOR(i, 0, n){
      cin >> v[i];
      sum += v[i];
      maxi = max(maxi, v[i]);
    }
    
    if(m >= n) cout << maxi << "\n";
    else cout << search(n, v, m, sum) << "\n";
  }
  
  return 0;
}