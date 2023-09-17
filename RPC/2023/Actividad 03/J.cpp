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
#define MAX 1000005
 
using namespace std;
 
const ld EPSILON = 0.0000001;

int n, k;
int trie[MAX][26], nds = 1;
ll cnt[MAX];
ll val;

int add(string &s){
  int cr = 0, x;

  for(const auto &c: s){
    x = c - 'a';

    if(trie[cr][x] == 0) trie[cr][x] = nds++;
    cr = trie[cr][x];
    cnt[cr]++;
    val += cnt[cr] - 1;
  }

  return cr;
}

int del(string &s){
  int cr = 0, x;

  for(const auto &c: s){
    x = c - 'a';

    if(trie[cr][x] == 0) trie[cr][x] = nds++;
    cr = trie[cr][x];
    cnt[cr]--;
    val -= cnt[cr];
  }
  
  return cr;
}

bool isValid() {
  return val >= k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  vector<string> p(n);
  FOR(i, 0, n) cin >> p[i];
  val = 0;

  int l, r;
  l = r = 0;

  ll ans = 0;
  while(l < n) {
    while(!isValid() and r < n){
      add(p[r++]);
    }

    if(isValid()) ans += n - r + 1;
    del(p[l++]);
  }

  cout << ans << "\n";

  return 0;
}