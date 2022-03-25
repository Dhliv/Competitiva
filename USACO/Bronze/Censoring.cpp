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

vector<int> z, p;

int find(int x){
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int a, int b){
  int fa = find(a), fb = find(b);

  if(fa == fb) return;
  p[fb] = fa;
}

void kmp(string &s, string &t){
  int j = 0, n = s.size(), x, fx;
  z.resize(n);
  p.resize(n);
  FOR(i, 1, n) p[i] = i;
  deque<int> sons;
  
  FOR(i, 1, n){
    while(j > 0 and s[i] != s[j]) j = z[j - 1];
    if(s[i] == s[j]) j++;
    z[i] = j;

    if(j == t.size()){ // we found t
      x = i;
      sons.PB(x);
      x--;

      FOR(k, 0, t.size() - 1){
        fx = find(x);
        if(fx == x){
          sons.PB(x);
          x--;
        }else{
          sons.PB(fx);
          x = fx - 1;
        }
      }

      fx = find(x);

      while(!sons.empty()){
        x = sons.F();
        sons.P_F();
        merge(fx, x);
      }

      j = z[fx];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("censor.in");
  ofstream cout("censor.out");

  string s, t, ns;
  cin >> s >> t;
  ns = t + "#" + s;

  kmp(ns, t);

  FOR(i, t.size() + 1, ns.size()){
    if(i == find(i)) cout << ns[i];
  }

  cout << "\n";
  
  return 0;
}
