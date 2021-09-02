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
#define MAX 4000005
#define LT 75

using namespace std;

int trie[MAX][LT], sum[MAX], nds, T;
ll ans;

bool comp(string &a, string &b){
  return a.size() > b.size();
}

void add(string &s){
  int cr = 0, x;
  
  for(char c: s){
    x = c - '0';
    if(trie[cr][x] == 0) trie[cr][x] = nds++;
    cr = trie[cr][x];
    sum[cr]++;
  }
  
  return;
}

void qr(string &s){
  int cr = 0, x, res;
  
  for(char c: s){
    x = c - '0';
    cr = trie[cr][x];
    ans += T + sum[cr] - 2;
    T = sum[cr];
    sum[cr]--;
    if(T == 1) return;
  }
  
  ans += T + sum[cr] - 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, id = 1, maxi, inia, fina, iniA, finA;
  
  while(cin >> n, n){
    nds = 1;
    maxi = 0;
    vector<string> p(n);
    FOR(i, 0, n){
      cin >> p[i];
      maxi += p[i].size();
    }
    
    maxi++;
    FOR(i, 0, maxi){
      FOR(j, 0, LT) trie[i][j] = 0;
      sum[i] = 0;
    }
    
    FOR(i, 0, n) add(p[i]);
    
    sort(p.begin(), p.end(), comp);
    
    ans = 0;
    FOR(i, 0, n){
      T = n - i;
      qr(p[i]);
    }
    
    cout << "Case " << id++ << ": " << ans << "\n";
  }
  
  return 0;
}