#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
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

struct dt{
  int back, front;

  dt(){}
  dt(int back, int front) : front(front), back(back){}
};

vector<vector<int> > dp(200005, vector<int> (2));
vector<dt> B;
string s;

int f(int i, bool hasBack){
  if(i == B.size()) return 0;
  int &ans = dp[i][hasBack];
  if(ans != -1) return ans;

  ans = B[i].front + f(i + 1, false);
  if(hasBack) ans = max(ans, B[i].back + f(i + 1, true));

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;

  while(t--){
    cin >> s;
    int pos = 0;
    B.clear();
    FOR(i, 0, s.size()){
      if(s[i] == 'A') continue;
      if(B.size()) B.B().front = i - pos;
      B.PB(dt(i - pos, 0));
      pos = i + 1;
    }

    if(B.size()) B.B().front = s.size() - pos;

    FOR(i, 0, B.size()){
      //cout << B[i].back << " " << B[i].front << "\n";
      FOR(j, 0, 2) dp[i][j] = -1;
    }

    if(B.size()) cout << f(0, 1) << "\n";
    else cout << "0\n";
  }

  return 0;
}