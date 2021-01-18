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
#define MAX 22

using namespace std;

int dp[MAX][MAX][MAX], n, data[MAX];
map<int, int> ord;

int f(int i, int d, int s){
  if(i == n) return s;
  if(dp[i][d][s] != -1) return dp[i][d][s];
  
  int maxi, r;
  
  r = ord[data[i]];
  
  if(r >= d) maxi = f(i + 1, r, s + 1);
  maxi = max(maxi, f(i + 1, d, s));
  
  return dp[i][d][s] = maxi;
}

int main(){
  int aux, cont, r[MAX];
  string ent, d;
  cin >> n;
  FOR(i, 0, n){
    cin >> aux;
    ord.insert(MP(i + 1, aux - 1));
  }
  
  getline(cin, ent);
  while(getline(cin, ent)){
    if(ent.size() <= 2){
      n = stoi(ent);
      ord.clear();
      
      FOR(i, 0, n){
        cin >> aux;
        ord.insert(MP(i + 1, aux - 1));
      }
      
      getline(cin, ent);
    }else{
      d = "";
      cont = 0;
      FOR(i, 0, ent.size()){
        if(i + 1 == ent.size() or isspace(ent[i])){
          if(i + 1 == ent.size()) d += ent[i];
          r[cont++] = stoi(d);
          d = "";
        }else d += ent[i];
      }
      
      FOR(i, 0, n) data[r[i] - 1] = i + 1;
      
      memset(dp, -1, sizeof(dp));
      cout << f(0, 0, 0) << "\n";
    }
  }
  
  return 0;
}