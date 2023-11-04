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
#define MAX 5001

using namespace std;

const ld EPSILON = 0.0000000001;

struct num{
  string n;
  vector<int> sum;

  num(){}
  num(int x){
    n = to_string(x);
    sum.assign(n.size() + 1, 0);

    FOR(i, 0, n.size()) sum[i + 1] = sum[i] + n[i] - '0';
  }

  int size(){return n.size();}

  int get(int i, int j){
    return sum[j] - sum[i];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  vector<num> p(n);
  ll ans = 0;
  vector<map<int, ll> > m(6);
  FOR(i, 0, n){
    int x; cin >> x;
    p[i] = num(x);
    int sum = p[i].get(0, p[i].size());
    auto it = m[p[i].size()].find(sum);
    if(it != m[p[i].size()].end()) it->s++;
    else m[p[i].size()].insert(MP(sum, 1));
  }

  FOR(i, 0, n){
    int cnt = 1;
    //cout << i << ": ";
    for(int j = p[i].size(); j >= (p[i].size() & 1 ? 1 : 2); j -= 2){
      if(j == p[i].size()){
        int sum = p[i].get(0, p[i].size());
        auto it = m[j].find(sum);
        if(it != m[j].end()) ans += it->s;
        continue;
      }

      // add to left
      //cout << "IN " << j << " -> [0, " << cnt << "] && [" << cnt << ", " << p[i].size() << "]; ";
      int sumL = p[i].get(0, cnt);
      int sumR = p[i].get(cnt, p[i].size());
      auto it = m[j].find(sumR - sumL);
      if(it != m[j].end()) ans += it->s;

      //cout << "[0, " << p[i].size() - cnt << "] && [" << p[i].size() - cnt << ", " << p[i].size() << "]; ";
      // add to right
      sumL = p[i].get(0, p[i].size() - cnt);
      sumR = p[i].get(p[i].size() - cnt, p[i].size());
      it = m[j].find(sumL - sumR);
      if(it != m[j].end()) ans += it->s;
      cnt++;
    }
  }

  cout << ans << "\n";

  return 0;
}