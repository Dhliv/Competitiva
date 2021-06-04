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
#define MAX 1000005

using namespace std;

int trie[MAX][26], nds = 1, sum[MAX];

void add(string &s){
  int cr = 0, x;
  
  for(char c : s){
    x = c - 'a';
    if(trie[cr][x] == 0) trie[cr][x] = nds++;
    cr = trie[cr][x];
    sum[cr]++;
  }
}

int qr(string &s){
  int cr = 0, x;
  
  for(char c : s){
    x = c - 'a';
    if(trie[cr][x] == 0) return 0;
    cr = trie[cr][x];
    if(sum[cr] == 0) return 0;
  }
  
  return sum[cr];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, q;
  cin >> n >> q;
  
  memset(trie, 0, sizeof(trie));
  memset(sum, 0, sizeof(sum));
  
  string s;
  
  FOR(i, 0, n){
    cin >> s;
    add(s);
  }
  
  FOR(i, 0, q){
    cin >> s;
    cout << qr(s) << "\n";
  }

  return 0;
}