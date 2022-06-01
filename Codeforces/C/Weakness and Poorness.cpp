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
#define MAX 200000

using namespace std;

ld epsi = 1e-13;
int n;
vector<ld> p(MAX), sp(MAX + 1), sn(MAX + 1);

ld poorness(ld x){
  ld maxi = LLONG_MIN;

  FOR(i, 1, n + 1){
    sp[i] = sp[i - 1] + p[i - 1] - x;
    if(sp[i] < epsi) sp[i] = 0.0;

    sn[i] = sn[i - 1] - (p[i - 1] - x);
    if(sn[i] < epsi) sn[i] = 0.0;

    if(maxi < sp[i]) maxi = sp[i];
    if(maxi < sn[i]) maxi = sn[i];

    //cout << i << ": " << sp[i] << " & " << sn[i] << "\n";
  }

  return maxi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(9);

  cin >> n;
  FOR(i, 0, n) cin >> p[i];

  ld l = -2000000000.0, r = 2000000000.0, m, tres = 3.0, m4, x, y, z;

  while(fabs(l - r) > epsi){
    m = l + (r - l)/tres;
    m4 = r - (r - l)/tres;
    x = poorness(m);
    y = poorness(m4);

    //cout << l << " " << r << ":: " << m << " = " << x << " && " << m4 << " = " << y << "\n";

    if(x < y){
      r = m4;
    }else if (x > y){
      l = m;
    }else{
      l = m;
      r = m4;
    }
  }

  cout << fixed << poorness(l) << "\n";

  return 0;
}