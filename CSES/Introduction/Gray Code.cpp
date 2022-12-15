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

int has[1 << 16];
int i;
int n;
int maxi;
bool found;

void f(int a){
  if(i == maxi + 1){
    found = true;
    return;
  }

  int x;
  FOR(j, 0, n){
    x = a ^ (1 << j);
    if(has[x]) continue;
    has[x] = i++;

    f(x);

    if(found) return;
    has[x] = 0;
    i--;
  }
}

void printBits(int &x){
  FORI(i, n - 1, 0) cout << ((x & (1 << i)) ? '1' : '0');
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  i = 1;
  maxi = 1 << n;
  found = false;
  FOR(i, 0, maxi) has[i] = 0;

  has[0] = 1;
  i++;
  f(0);

  vector<pair<int, int> > ans(maxi);
  FOR(i, 0, maxi){
    ans[i] = MP(has[i], i);
  }

  sort(ans.begin(), ans.end());

  FOR(i, 0, ans.size()){
    printBits(ans[i].s);
  }

  return 0;
}