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

int dp[101][2], n;

int f(int i, int b, string &s){
  if(i == n) return 0;
  int &ans = dp[i][b], x;
  if(ans != -1) return ans;

  if(s[i] == '?'){
    ans = (b == 0 ? 1 : 0) + f(i + 1, 0, s);
    ans = min((b == 1 ? 1 : 0) + f(i + 1, 1, s), ans);
  }else{
    x = (s[i] == 'R' ? 0 : 1);
    ans = (b == x ? 1 : 0) + f(i + 1, x, s);
  }

  return ans;
}

void look(int i, int b, string &s){
  if(i == n) return;
  int ans = dp[i][b], x, y;

  if(s[i] == '?'){
    x = (b == 0 ? 1 : 0) + f(i + 1, 0, s);
    y = (b == 1 ? 1 : 0) + f(i + 1, 1, s);
    if(ans == x){
      cout << 'R';
      look(i + 1, 0, s);
    }else{
      cout << 'B';
      look(i + 1, 1, s);
    }
  }else{
    x = (s[i] == 'R' ? 0 : 1);
    cout << s[i];
    look(i + 1, x, s);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, mini;
  string s;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> s;

    memset(dp, -1, sizeof(dp));

    if(s[0] == '?'){
      mini = f(1, 1, s);
      mini = min(mini, f(1, 0, s));
      if(mini == f(1, 1, s)){
        cout << 'B';
        look(1, 1, s);
      }else{
        cout << 'R';
        look(1, 0, s);
      }
    }else{
      mini = f(1, (s[0] == 'R' ? 0 : 1), s);
      cout << s[0];
      look(1, (s[0] == 'R' ? 0 : 1), s);
    }

    cout << "\n";
  }

  return 0;
}