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

vector<ll> z;

void kmp(string &s){
  int l, n = s.size();
  z.resize(n);
  
  FOR(i, 1, n){
    l = z[i - 1];
    
    while(l > 0 and s[i] != s[l]) l = z[l - 1];
    
    if(s[i] == s[l]) l++;
    z[i] = l;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ll k, n, ans, t;
  string s;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> s >> k;
    kmp(s);
    n = s.size();
    
    ans = n + (n - z[n - 1])*(k - 1);
    cout << ans << "\n";
  }

  return 0;
}