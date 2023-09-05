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

using namespace std;

const ld EPSILON = 0.0000001;

struct contestant {
  int pos, qual, words;

  contestant(){}

  contestant(int pos, int qual, int words){
    this->pos = pos;
    this->qual = qual;
    this->words = words;
  }
};

bool comp(const contestant &a, const contestant &b){
  return a.qual > b.qual;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, q, w;

  while(t--){
    cin >> n;
    vector<contestant> p(n);
    FOR(i, 0, n){
      cin >> w >> q;
      p[i] = contestant(i + 1, q, w);
    }

    sort(p.begin(), p.end(), comp);

    FOR(i, 0, n){
      if(p[i].words <= 10){
        cout << p[i].pos << "\n";
        break;
      }
    }
  }
 
  return 0;
}