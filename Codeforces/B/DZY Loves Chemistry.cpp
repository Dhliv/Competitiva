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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int g;

int find(int x, vector<int> &p){
  if(p[x] == x) return x;
  return p[x] = find(p[x], p);
}

void merge(int a, int b, vector<int> &s, vector<int> &p){
  int fa, fb;
  fa = find(a, p);
  fb = find(b, p);

  if(fa == fb) return;

  if(s[fb] > s[fa]) swap(fa, fb);

  g--;
  p[fb] = fa;
  s[fa] += s[fb];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m; cin >> n >> m;
  int x, y;
  g = n;
  vector<int> p(n + 1, 1), s(n + 1, 1);

  FOR(i, 2, n + 1) p[i] = i;

  FOR(i, 0, m){
    cin >> x >> y;
    merge(x, y, s, p);
  }

  cout << (((ll) 1) << (n - g)) << "\n";

  return 0;
}