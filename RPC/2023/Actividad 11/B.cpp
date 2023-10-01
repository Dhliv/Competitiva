#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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

struct client{
  int id, ar, w, pat;

  client(){}
  client(int id, int ar, int w, int pat) : id(id), ar(ar), w(w), pat(pat){}
};

bool comp(client &a, client &b){
  return a.ar < b.ar;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  vector<client> p(n);
  int t = 0;
  int id, ar, w, pat;
  FOR(i, 0, n){
    cin >> id >> ar >> w >> pat;
    p[i] = client(id, ar, w, pat);
  }

  //sort(p.begin(), p.end(), comp);

  FOR(i, 0, n){
    if(t <= p[i].ar + p[i].pat){
      cout << p[i].id << "\n";
      t = max(p[i].ar, t) + p[i].w;
    }
  }

  return 0;
}