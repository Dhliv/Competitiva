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
  string s;

  FOR(ab, 0, t){
    vector<vector<int> > hash(26);
    cin >> s;

    FOR(i, 0, s.size()){
      hash[s[i] - 'a'].PB(i + 1);
    }

    cout << abs(s[0] - s[s.size() - 1]) << " ";
    deque<int> ans;

    if(s[0] > s[s.size() - 1]){
      FORI(i, s[0] - 'a', s[s.size() - 1] - 'a'){
        FOR(j, 0, hash[i].size()){
          ans.PB(hash[i][j]);
        }
      }
    }else{
      FOR(i, s[0] - 'a', s[s.size() - 1] - 'a' + 1){
        FOR(j, 0, hash[i].size()){
          ans.PB(hash[i][j]);
        }
      }
    }

    cout << ans.size() << "\n";
    FOR(i, 0, ans.size()) cout << ans[i] << " ";

    cout << "\n";
  }

  return 0;
}