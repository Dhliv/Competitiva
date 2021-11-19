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

  vector<pair<int, int> > maxi(2501, MP(0, 1));
  int dvs, n;

  FOR(i, 1, 2501){
    n = sqrt(i);
    if(n*n == i) dvs = 1;
    else{
      n++;
      dvs = 0;
    }

    FOR(j, 1, sqrt(i)){
      if(i%j == 0) dvs += 2;
    }

    if(dvs > maxi[i - 1].f) maxi[i] = MP(dvs, i);
    else maxi[i] = maxi[i - 1];
  }

  int t;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    cout << maxi[n].s << "\n";
  }

  return 0;
}