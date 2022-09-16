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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  string s, ans;
  char k;
  int n;

  FOR(ab, 0, t){
    cin >> n >> s;
    deque<char> ans;

    FORI(i, s.size() - 1, 0){
      if(s[i] == '0'){
        k = 'a';
        k += (s[i - 2] - '0')*10;
        k += s[i - 1] - '0' - 1;
        i -= 2;
        ans.PF(k);
      }else{
        ans.PF(s[i] - '0' + 'a' - 1);
      }
    }

    FOR(i, 0, ans.size()){
      cout << ans[i];
    }

    cout << "\n";
  }

  return 0;
}