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

int n, lft;
set<string> ans;

void imp(int v, string s){
  if(ans.size() == n) return;
  if(v == n){
    lft--;
    string w = s + s;
    int l = 0, r = 2*n - 1;
    FOR(j, 0, n){
      if(s[j] == '1'){
        w[l++] = '(';
        w[r--] = ')';
      }else{
        w[l++] = '(';
        w[l++] = ')';
      }
    }
    ans.insert(w);
    return;
  }

  imp(v + 1, s + "1");
  imp(v + 1, s + "2");
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, l, r; cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    lft = n;
    ans.clear();
    imp(0, "");

    string s = "", w;
    FOR(i, 0, 2*n) s.PB('0');
  
    for(auto p : ans){
      l = 0;
      r = 2*n - 1;
      w = p;

      cout << p << "\n";
  }
 
  return 0;
} 