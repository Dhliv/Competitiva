#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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
#define mod 998244353
#define MAX 200005

using namespace std;

pair<ll, ll> dp[MAX][2]; // removed elements, diff ways to erase them;
string s;
int n;

pair<ll, ll> f(int i, bool last){
  if(i == n) return MP(0, 1);
  pair<ll, ll> &ans = dp[i][last], aux;
  if(ans.f != -1) return ans;

  ans = f(i + 1, last);
  ans.f++; // borrar un elemento
  if(last != s[i] - '0'){
    aux = f(i + 1, 1 - last);
    if(aux.f != ans.f){
      if(aux.f < ans.f) ans = aux;
    }else ans.s = (ans.s + aux.s)%mod;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;

  while(t--){
    cin >> s;
    n = s.size();

    FOR(i, 0, n){
      FOR(j, 0, 2) dp[i][j] = MP(-1, -1);
    }

    pair<ll, ll> a1, a2, ans;
    a1 = f(0, 0);
    a2 = f(0, 1);
    if(a1.f != a2.f){
      if(a1.f < a2.f) ans = a1;
      else ans = a2;
    }else ans = MP(a1.f, (a1.s + a2.s)%mod);

    FORI(i, ans.f, 2) ans.s = (ans.s*i)%mod;

    cout << ans.f << " " << ans.s << "\n";
  }

  return 0;
}