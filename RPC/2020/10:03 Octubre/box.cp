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

int maxi(vector<int> &ans, int a, int b){
  int res = -1;
  
  FOR(i, a, b){
    res = max(res, ans[i]);
  }
  
  return res;
}

int main(){
  int b, r, v, c, h, s;
  cin >> b >> r;
  vector<int> ans(b);
  
  FOR(i, 0, r){
    cin >> h >> v >> c;
    
    s = maxi(ans, c - 1, h + c - 1) + v;
    FOR(j, c - 1, h + c - 1){
      ans[j] = s;
    }
  }
  
  cout << *(max_element(ans.begin(), ans.end())) << "\n";
  
  return 0;
}