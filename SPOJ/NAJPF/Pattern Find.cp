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

vector<int> z;

void kmp(string &s){
  int j, n = s.size();
  z.resize(n);
  
  FOR(i, 1, n){
    j = z[i - 1];
    while(j > 0 and s[i] != s[j]) j = z[j - 1];
    if(s[i] == s[j]) j++;
    z[i] = j;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t, id = 0, res;
  string a, b, s;
  cin >> t;
  
  FOR(ab, 0, t){
    if(id++) cout << "\n";
    cin >> a >> b;
    s = b + "#" + a;
    kmp(s);
    deque<int> ans;
    
    res = 2*b.size();
    FOR(i, b.size() + 1, s.size()){
      if(z[i] == b.size()) ans.PB(i + 1 - res);
    }
    
    if(ans.empty()) cout << "Not Found\n";
    else{
      cout << ans.size() << "\n" << ans.F();
      FOR(i, 1, ans.size()) cout << " " << ans[i];
      cout << "\n";
    }
  }

  return 0;
}