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
#define MAX 200005
 
using namespace std;
 
const ld EPSILON = 0.0000001;

int p[MAX], content[MAX][26], s[MAX];

int find(int x){
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

void merge(int a, int b){
  int fa = find(a), fb = find(b);
  if(fa == fb) return;

  if(s[fb] > s[fa]) swap(fa, fb);
  s[fa] += s[fb];
  p[fb] = fa;
  FOR(i, 0, 26){
    content[fa][i] += content[fb][i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, k, x; cin >> t;
  string st, curse;

  while(t--){
    cin >> n >> k >> st >> curse;
    FOR(i, 0, n){
      p[i] = i;
      FOR(j, 0, 26) content[i][j] = 0;
      s[i] = 1;
      content[i][st[i] - 'a'] = 1;
    }

    int bound = n - k;
    FOR(i, 0, bound){
      merge(i, i + k);
      if(i + k + 1 < n) merge(i, i + k + 1);
    }

    bool able = true;
    FOR(i, 0, n){
      x = find(i);
      if(content[x][curse[i] - 'a'] == 0){
        able = false;
        break;
      }

      content[x][curse[i] - 'a']--;
    }

    cout << (able ? "YES" : "NO") << "\n";
  }
 
  return 0;
}