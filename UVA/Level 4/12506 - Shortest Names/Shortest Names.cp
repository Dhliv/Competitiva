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

ll ans;

struct trie{
  bool ex;
  trie *nx[26];
  int sum[26];
  
  void ini(){
    FOR(i, 0, 26){
      nx[i] = new trie(false);
      sum[i] = 0;
    }
  }
  
  trie(bool create){
    ex = create ? 1 : 0;
    if(create) ini();
  }
  
  void add(string &s, int i){
    if(i == s.size()) return;
    int x = s[i] - 'a';
    if(nx[x]->ex == 0) nx[x] = new trie(true);
    nx[x]->add(s, i + 1);
    
    sum[x]++;
  }
  
  void look(int cs){
    FOR(i, 0, 26){
      if(nx[i]->ex == 0) continue;
      if(sum[i] == 1) ans += cs;
      else nx[i]->look(cs + 1);
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t, n;
  string s;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    trie tr(true);
    
    FOR(i, 0, n){
      cin >> s;
      tr.add(s, 0);
    }
    
    ans = 0;
    tr.look(1);
    cout << ans << "\n";
  }
  
  return 0;
}