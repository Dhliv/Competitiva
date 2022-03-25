#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

struct meas{
  int t;
  string reg, cow;
};

bool comp(meas &a, meas &b){
  return a.t < b.t;
}

void augment(map<string, int> &cows, meas &a){
  int num = stoi(a.reg.substr(1));
  num *= a.reg[0] == '+' ? 1 : -1;

  cows[a.cow] += num;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("measurement.in");
  ofstream cout("measurement.out");

  int n; cin >> n;
  int maxi = INF;
  meas a;
  vector<meas> p(n);
  map<string, int> cows;
  set<string> act, nx;
  cows.insert(MP("Mildred", 7));
  cows.insert(MP("Elsie", 7));
  cows.insert(MP("Bessie", 7));

  act.insert("Mildred");
  act.insert("Elsie");
  act.insert("Bessie");

  FOR(i, 0, n){
    cin >> p[i].t >> p[i].cow >> p[i].reg;
  }

  sort(p.begin(), p.end(), comp);

  int ans = 0;
  FOR(i, 0, n){
    augment(cows, p[i]);
    maxi = 0;

    for(auto cow: cows){
      maxi = max(maxi, cow.s);
    }

    for(auto cow: cows){
      if(cow.s == maxi) nx.insert(cow.f);
    }

    if(nx != act){
      ans++;
      nx.swap(act);
    }
    nx.clear();
  }

  cout << ans << "\n";
  
  return 0;
}
