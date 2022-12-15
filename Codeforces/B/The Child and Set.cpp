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

bool comp(const pair<int, int> &a, const pair<int, int> &b){
  return a.f > b.f;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int sum, lim; cin >> sum >> lim;
  vector<pair<int, int> > p(lim);

  FOR(i, 1, lim + 1){
    FOR(j, 0, 30){
      if(i & (1 << j)){
        p[i - 1] = MP((1 << j), i);
        break;
      }
    }
  }

  sort(p.begin(), p.end(), comp);

  int sum2 = 0;
  deque<int> ans;
  FOR(i, 0, lim){
    if(sum2 + p[i].f <= sum){
      sum2 += p[i].f;
      ans.PB(p[i].s);
    }
  }

  if(sum2 == sum){
    cout << ans.size() << "\n";
    FOR(i, 0, ans.size()) cout << ans[i] << " ";
    cout << "\n";
  }else cout << "-1\n";

  return 0;
}