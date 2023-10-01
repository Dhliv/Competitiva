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

using namespace std;

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void merge(int a, int b, vector<int> &p, vector<int> &s){
  int fa = find(a, p), fb = find(b, p);
  if(fa == fb) return;
  if(s[fa] > s[fb]) swap(fa, fb);

  p[fa] = fb;
  s[fb] += s[fa];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  vector<int> p(n + 1), s(n + 1, 1);
  FOR(i, 1, n + 1) p[i] = i;

  int x;
  FOR(i, 1, n + 1){
    cin >> x;
    merge(i, x, p, s);
  } 

  int ops = 0;
  FOR(i, 1, n + 1){
    if(i != find(i, p)) continue;
    ops += s[i] - 1;
  }

  cout << (ops%2 ? "Smokin Joe!" : "Oh No!") << "\n";

  return 0;
}