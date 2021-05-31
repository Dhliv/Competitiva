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
  
  string a, w, s, ch, con;
  bool able;
  int t, tms, tm;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> a >> w >> s;
    map<char, int> id;
    deque<int> ans;
    
    FOR(i, 0, a.size()) id.insert(MP(a[i], id.size()));
    tm = a.size();
    z.resize(w.size() + 1 + s.size());
    
    FOR(i, 0, tm){
      ch = "";
      FOR(j, 0, w.size()) ch.PB(a[(id[w[j]] - i + tm)%tm]);
      
      con = ch + "#" + s;
      kmp(con);
      
      able = false;
      FOR(j, w.size() + 1, con.size()){
        if(z[j] == w.size()){
          if(able){
            able = false;
            break;
          }
          able = true;
        }
      }
      
      if(able) ans.PB((tm - i)%tm);
    }
    
    sort(ans.begin(), ans.end());
    if(ans.empty()) cout << "no solution\n";
    else if(ans.size() == 1) cout << "unique: " << ans.F() << "\n";
    else{
      cout << "ambiguous:";
      FOR(i, 0, ans.size()) cout << " " << ans[i];
      cout << "\n";
    }
  }

  return 0;
}