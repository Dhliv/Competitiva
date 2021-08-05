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
 
using namespace std;

bool comp(int &a, int &b){
  return a > b;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, x, y, maxi;
  string a;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    vector<vector<int> > f(5, vector<int> (n));

    FOR(i, 0, n){
      cin >> a;
      vector<int> ax(5);
      FOR(j, 0, a.size()) ax[a[j] - 'a']++;

      y = 0;
      FOR(j, 0, 5) y += ax[j];
      FOR(j, 0, 5){
        y -= ax[j];
        x = ax[j];
        f[j][i] = x - y;
        y += ax[j];
      }
    }

    FOR(i, 0, 5) sort(f[i].begin(), f[i].end(), comp);

    maxi = 0;
    FOR(i, 0, 5){
      x = 0;
      FOR(j, 0, n){
        x += f[i][j];
        if(x <= 0){
          maxi = max(maxi, (int)j);
          x = 0;
          break;
        }
      }

      if(x > 0) maxi = n;
    }

    cout << maxi << "\n";
  }

  return 0;
}
