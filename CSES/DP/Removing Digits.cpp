#include <bits/stdc++.h>
#define INF 100000000
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

int dp[1000001];

vector<int> g(string a){
	vector<int> c(10), ans;
	FOR(i, 0, a.size()){
		c[a[i] - '0']++;
	}

	FOR(i, 1, 10) if(c[i]) ans.PB(i);

	return ans;
}

int f(int x){
	if(x < 0) return INF;
	if(x == 0) return 0;
	int &ans = dp[x];
	if(ans != -1) return ans;

	vector<int> p = g(to_string(x));

	ans = INF;
	FOR(i, 0, p.size()){
		ans = min(ans, 1 + f(x - p[i]));
	}

	return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;

	memset(dp, -1, sizeof(dp));

	cout << f(n) << "\n";

  return 0;
}