#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
 
using namespace std;
 
const ld EPSILON = 0.0000001;

string s1, s2, virus;
int dp[101][101][101];
int kmpAutomata[101][256];

vector<int> kmp(string &s){
  vector<int> ans(s.size());
  int j = 0;

  FOR(i, 1, s.size()){
    while(j > 0 and s[i] != s[j]) j = ans[j - 1];
    if(s[i] == s[j]) j++;
    ans[i] = j;
  }

  return ans;
}

int f(int i, int j, int k){
  if(k == virus.size()) return 0;
  if(i == s1.size() or j == s2.size()) return 100;
  int &ans = dp[i][j][k];
  if(ans != -1) return ans;

  ans = f(i + 1, j, k);
  ans = max(ans, f(i, j + 1, k));

  if(s1[i] == s2[j]){
    if(virus[k] == s2[j]) ans = max(ans, 1 + f(i + 1, j + 1, k + 1));
    else ans = max(ans, 1 + f(i + 1, j + 1, kmpAutomata[k][s2[j]]));
  }

  return ans;
}

void reconstruct(int i, int j, int k){
  if(i == s1.size() or j == s2.size()) return;
  int &ans = dp[i][j][k];

  if(ans == f(i + 1, j, k)) reconstruct(i + 1, j, k);
  else if(ans == f(i, j + 1, k)) reconstruct(i, j + 1, k);
  else if(s1[i] == s2[j]){
    cout << s1[i];
    if(virus[k] == s2[j]) reconstruct(i + 1, j + 1, k + 1);
    else reconstruct(i + 1, j + 1, kmpAutomata[k][s2[j]]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s1 >> s2 >> virus;

  vector<int> ps = kmp(virus);

  FOR(i, 0, 101){
    FOR(j, 0, 256) kmpAutomata[i][j] = 0;
  }

  kmpAutomata[0][virus[0]] = 1;
  FOR(i, 1, virus.size()){
    FOR(j, 0, 256){
      if(virus[i] == j){
        kmpAutomata[i][j] = i + 1;
      }else{
        kmpAutomata[i][j] = kmpAutomata[ps[i - 1]][j];
      }
    }
  }

  memset(dp, -1, sizeof(dp));

  f(0, 0, 0);

  if(dp[0][0][0] <= 100) cout << "0\n";
  else{
    reconstruct(0, 0, 0);
    cout << "\n";
  }
 
  return 0;
}