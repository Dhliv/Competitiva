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
#define MAX 260005
 
using namespace std;
 
const ld EPSILON = 0.0000001;

int trie[MAX][26], nds = 1;
int fin[MAX], fail[MAX], val[MAX], sure_fail[MAX];
string A, B, s;

int add(string &s, int v){
  int cr = 0, x;

  for(const auto &c: s){
    x = c - 'a';

    if(trie[cr][x] == 0) trie[cr][x] = nds++;
    cr = trie[cr][x];
  }

  fin[cr] = 1;
  val[cr] = v;
  return cr;
}

void build(){
  int x, cr = 0;

  deque<int> q;
  q.PB(cr);

  while(!q.empty()){
    cr = q.F(); q.P_F();

    FOR(i, 0, 26){
      x = trie[cr][i];
      if(x) q.PB(x);

      if(cr == 0) continue;
      if(x == 0){
        trie[cr][i] = trie[fail[cr]][i];
        continue;
      }

      fail[x] = trie[fail[cr]][i];
      sure_fail[x] = fin[fail[x]] ? fail[x] : sure_fail[fail[x]];
      //cout << x << ": " << fail[x] << " & " << sure_fail[x] << "\n";
    }
  }
}

ll cal(int cr){
  ll v = 0;
  if(fin[cr]) v += val[cr];
  while(sure_fail[cr]){
    cr = sure_fail[cr];
    v += val[cr];
  }

  return v;
}

void pre(vector<ll> &p){
  int cr;
  ll v;

  FOR(i, 0, B.size()){
    v = 0;
    cr = 0;
    FOR(j, i, B.size()){
      cr = trie[cr][B[j] - 'a'];
      v += cal(cr);
    }

    p[i] = v;
  }
}

ll f(int cr, vector<ll> &dp){
  ll v = 0;
  ll mv = 0;
  ll ans = 0;
  int ccr, acr;
  int j;

  FOR(i, 0, B.size()){
    ccr = v = mv = 0;
    acr = cr;
    j = i;
    while(j < B.size()){
      acr = trie[acr][B[j] - 'a'];
      ccr = trie[ccr][B[j] - 'a'];
      if(acr == ccr) break;

      v += cal(acr);
      mv += cal(ccr);
      j++;
    }
    //cout << i << " & " << cr << ": " << v << ", " << mv << ", " << dp[i] << "\n";

    ans = max(ans, v + dp[i] - mv);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n;
  ll v; cin >> t;

  while(t--){
    nds = 1;
    cin >> A >> B >> n;
    FOR(i, 0, 26*n){
      FOR(j, 0, 26) trie[i][j] = 0;
      val[i] = fail[i] = sure_fail[i] = fin[i] = 0;
    }

    FOR(i, 0, n){
      cin >> s >> v;
      add(s, v);
    }

    build();
    vector<ll> inB(B.size());
    pre(inB);

    /*FOR(i, 0, B.size()) cout << inB[i] << " ";
    cout << "\n";*/

    ll ans = f(0, inB);
    int cr = 0;
    v = 0;
    FOR(i, 0, A.size()){
       cr = trie[cr][A[i] - 'a'];
       v += cal(cr);
       ans = max(ans, v + f(cr, inB));
    }

    cout << ans << "\n";
  }
 
  return 0;
}