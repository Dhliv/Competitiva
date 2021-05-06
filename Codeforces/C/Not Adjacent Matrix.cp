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

bool check(vector<vector<int> > &p){
  int n = p.size();
  bool able = true;
  
  FOR(i, 0, n){
    FOR(j, 0, n){
      if(i + 1 < n and abs(p[i][j] - p[i + 1][j]) == 1) able = false;
      if(j + 1 < n and abs(p[i][j] - p[i][j + 1]) == 1) able = false;
    }
  }
  
  return able;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t, n, id;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    if(n == 3){
      cout << "2 9 7\n4 6 3\n1 8 5\n";
    }else{
      id = 1;
      vector<vector<int> > p(n, vector<int> (n));
      
      FOR(i, 0, n){
        for(int j = 0; j < n; j += 2){
          p[i][j] = id++;
        }
      }
      
      FOR(i, 0, n){
        for(int j = 1; j < n; j += 2){
          p[i][j] = id++;
        }
      }
      
      if(check(p)){
        FOR(i, 0, n){
          cout << p[i][0];
          FOR(j, 1, n) cout << " " << p[i][j];
          cout << "\n";
        }
      }else cout << "-1\n";
    }
  }
  
  return 0;
}