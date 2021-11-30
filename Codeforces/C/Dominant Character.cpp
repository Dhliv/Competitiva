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

bool ch(int &a, int &b, string &s){
  int cnt[3] = {0};

  FOR(i, a, b + 1){
    cnt[s[i] - 'a']++;
  }

  if(cnt[0] > cnt[1] and cnt[0] > cnt[2]) return true;
  return false;
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, mini;
  cin >> t;
  string s;

  FOR(ab, 0, t){
    cin >> n >> s;
    deque<int> c;

    FOR(i, 0, n) if(s[i] == 'a') c.PB(i);

    mini = INF;
    if(c.size() >= 2){
      if(c[1] - c[0] <= 3 and ch(c[0], c[1], s)) mini = min(mini, c[1] - c[0] + 1);
      FOR(i, 2, c.size()){ 
        if(c[i] - c[i - 1] <= 3 and ch(c[i - 1], c[i], s)) mini = min(mini, c[i] - c[i - 1] + 1);
        if(c[i] - c[i - 2] == 6 and ch(c[i - 2], c[i], s)) mini = min(mini, c[i] - c[i - 2] + 1);
      }
    }

    cout << (mini == INF ? -1 : mini) << "\n";
  }
  
  return 0;
}