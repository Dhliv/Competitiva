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

struct sensor{
  int a, b;
  string t;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("traffic.in");
  ofstream cout("traffic.out");

  int n; cin >> n;
  vector<sensor> p(n);
  sensor aux;
  int ai, bi, af, bf;

  ai = af = 0;
  bi = bf = 1000;

  FOR(i, 0, n) cin >> p[i].t >> p[i].a >> p[i].b;

  FOR(i, 0, n){
    if(p[i].t == "on"){
      af += p[i].a;
      bf += p[i].b;
    }else if(p[i].t == "off"){
      bf -= p[i].a;
      af -= p[i].b;
    }else{
      af = max(af, p[i].a);
      bf = min(bf, p[i].b);
    }
  }

  FORI(i, n - 1, 0){
    if(p[i].t == "on"){
      bi -= p[i].a;
      ai -= p[i].b;
    }else if(p[i].t == "off"){
      ai += p[i].a;
      bi += p[i].b;
    }else{
      ai = max(ai, p[i].a);
      bi = min(bi, p[i].b);
    }
  }

  bi = min(bi, 1000);
  bf = min(bf, 1000);
  ai = max(ai, 0);
  af = max(af, 0);

  cout << ai << " " << bi << "\n" << af << " " << bf << "\n";
  
  return 0;
}
