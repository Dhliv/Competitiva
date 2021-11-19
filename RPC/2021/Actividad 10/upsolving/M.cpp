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
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  const int l = 1000001;
  vector<int> p(l);
  vector<pair<int, int> > maxi(l, MP(0, 1));

  FOR(i, 2, l){
    for(int j = i; j < l; j += i) p[j]++;
  }

  FOR(i, 2, l){
    if(p[i] > maxi[i - 1].f) maxi[i] = MP(p[i], i);
    else maxi[i] = maxi[i - 1];
  }

  int t, n;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    cout << maxi[n].s << "\n";
  }
  
  return 0;
}