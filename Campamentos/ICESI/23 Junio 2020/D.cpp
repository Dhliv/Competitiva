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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int stalls, cows;

bool acomodar(vector<int> v, int x){
  int sta = v[0], aco = 1;
  
  FOR(i, 1, stalls){
    if((v[i] - sta) >= x){
      sta = v[i];
      aco++;
      if(aco == cows)
        return true;
    }
  }
  
  return false;
}

void solve(vector<int> v){
  int high = v[stalls-1] - v[0], low = 1, mid;
  
  while(low <= high){
    mid = (high + low)/2;
    if(acomodar(v, mid)) low = mid + 1;
    else high = mid - 1;
  }
  
  cout << high << "\n";
}

int main(){
  int cases;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> stalls >> cows;
    vector<int> v(stalls);
    
    FOR(i, 0, stalls)
      cin >> v[i];
      
    sort(v.begin(), v.end());
    
    solve(v);
  }
  
  return 0;
}