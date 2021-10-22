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
 
using namespace std;
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y;
  cin >> n >> m;
  vector<bool> s(n + 1);
  vector<int> gr(n + 1, -1);
  vector<int> tams(2);
  deque<int> nds[2];

  int left = n;

  FOR(i, 0, m){
    cin >> x >> y;

    if(gr[x] != -1 and gr[y] != -1) continue;

    if(gr[x] != -1){
      left--;
      gr[y] = gr[x];
      s[y] = 1;
      tams[gr[y]]++;
      nds[gr[y]].PB(y);
    }else if(gr[y] != -1){
      left--;
      gr[x] = gr[y];
      s[x] = 1;
      tams[gr[x]]++;
      nds[gr[y]].PB(x);
    }else{
      if(tams[0] == 0){
        left -= 2;
        s[x] = s[y] = 1;
        gr[x] = gr[y] = 0;
        tams[0] += 2;
      }else if(tams[1] == 0 and left == 2){
        s[x] = s[y] = 1;
        gr[x] = gr[y] = 1;
        tams[1] += 2;
      }else{
        if(tams[0] >= tams[1]){
          left -= 2;
          s[x] = s[y] = 1;
          gr[x] = gr[y] = 0;
          tams[0] += 2;
        }else{
          s[x] = s[y] = 1;
          gr[x] = gr[y] = 1;
          tams[1] += 2;
        }
      }

      nds[gr[y]].PB(y);
      nds[gr[y]].PB(x);
    }
  }

  FOR(i, 1, n + 1){
    if(s[i] == 1) continue;

    if(tams[0] == 0){
      s[i] = 1;
      gr[i] = 0;
      tams[0]++;
    }else if(tams[1] == 0){
      s[i] = 1;
      gr[i] = 1;
      tams[1]++;
    }else{
      if(tams[0] >= tams[1]){
        s[i] = 1;
        gr[i] = 0;
        tams[0]++;
      }else{
        s[i] = 1;
        gr[i] = 1;
        tams[1]++;
      }
    }

    nds[gr[i]].PB(i);
  }

  cout << tams[0]*tams[1] << "\n";

  for(int x : nds[0]){
    for(int y : nds[1]) cout << x << " " << y << "\n";
  }

  return 0;
}