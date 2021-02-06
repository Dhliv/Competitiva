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

int res[6][6], id[6], x;
bool s[10];

void f(int in){
  if(in == 6){
    FOR(i, 0, 6){
      x = 0;
      FOR(j, 0, 6) x += res[i][j]*id[j];
      if(x != 0) return;
    }
    cout << id[0] << " " << id[1] << " " << id[2] << " " << id[3] << " " << id[4] << " " << id[5] << "\n";
  }else{
    FOR(i, 0,10){
      if(s[i]) continue;
      id[in] = i;
      s[i] = 1;
      f(in + 1);
      s[i] = 0;
    }
  }
  
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cases, x;
  string ent;
  cin >> cases;
  
  FOR(ab, 1, cases + 1){
    memset(res, 0, sizeof(res));
    memset(s, 0, sizeof(s));
    vector<vector<string> > data(3, vector<string> (3));
    FOR(i, 0, 3){
      FOR(j, 0, 3){
        cin >> ent;
        res[i][ent[0] - 'A'] += 1;
        if(j == 2) res[i][ent[0] - 'A'] += -2;
        if(ent.size() > 1){
          res[i][ent[0] - 'A'] += 9;
          res[i][ent[1] - 'A'] += 1;
          if(j == 2) res[i][ent[0] - 'A'] += -18;
          if(j == 2) res[i][ent[1] - 'A'] += -2;
        }
        data[i][j] = ent;
      }
    }
    
    FOR(j, 0, 3){
      FOR(i, 0, 3){
        ent = data[i][j];
        res[j + 3][ent[0] - 'A'] += 1;
        if(i > 0) res[j + 3][ent[0] - 'A'] += -2;
        if(ent.size() > 1){
          res[j + 3][ent[0] - 'A'] += 9;
          res[j + 3][ent[1] - 'A'] += 1;
          if(i > 0) res[j + 3][ent[0] - 'A'] += -18;
          if(i > 0) res[j + 3][ent[1] - 'A'] += -2;
        }
      }
    }
    
    cout << "Case #" << ab << ":\n";
    f(0);
    cout << "\n";
  }
  
  return 0;
}