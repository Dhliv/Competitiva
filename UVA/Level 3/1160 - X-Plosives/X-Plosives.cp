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
#define MAX 100005

using namespace std;

int ans;

void ini(vector<int> &p, vector<int> &s, vector<int> &prs){
  FOR(i, 0, MAX){
    p[i] = i;
    s[i] = 1;
    prs[i] = 0;
  }
  return;
}

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void merge(int &a, int &b, vector<int> &p, vector<int> &s, vector<int> &prs){
  if(s[b] > s[a]) swap(a, b);
  
  p[b] = a;
  s[a] += s[b];
  prs[a] += prs[b] + 1;
  
  if(prs[a] == s[a]){
    ans++;
    prs[a] -= (prs[b] + 1);
    s[a] -= s[b];
    p[b] = b;
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int x, y, xf, yf;
  vector<int> p(MAX), s(MAX), prs(MAX);
  
  while(cin >> x >> y){
    ini(p, s, prs);
    merge(x, y, p, s, prs);
    ans = 0;
    
    while(cin >> x, x != -1){
      cin >> y;
      xf = find(x, p);
      yf = find(y, p);
      
      if(xf != yf) merge(xf, yf, p, s, prs);
      else{
        prs[xf]++;
        if(prs[xf] == s[xf]){
          ans++;
          prs[xf]--;
        }
      }
    }
    
    cout << ans << "\n";
  }

  return 0;
}