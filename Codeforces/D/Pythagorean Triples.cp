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

int look(int n, deque<int> &p){
  int l = 0, h = p.size() - 1, mid;
  
  while(l <= h){
    mid = (l + h)/2;
    if(p[mid] > n) h = mid - 1;
    else l = mid + 1;
  }
  
  return l;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t, n, MAX = 100000;
  ll a, b, c, x;
  deque<int> ans;
  
  for(ll i = 3; i < MAX; i += 2){
    x = i*i;
    b = x/2;
    c = b + 1;
    a = i;
    x = max(a, max(b, c));
    if(x <= 1000000000) ans.PB(x);
  }
  
  sort(ans.begin(), ans.end());
  
  cin >> t;
  FOR(i, 0, t){
    cin >> n;
    cout << look(n, ans) << "\n";
  }
  
  return 0;
}