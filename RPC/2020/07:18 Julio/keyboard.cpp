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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  vector<vector<int> > ady(26, vector<int> (26));
  vector<string> n{"abcdefghi", "jklmnopqr", "stuvwxyz"};
  
  FOR(i, 0, 3){
    FOR(j, 0, n[i].size()){
      if(i - 1 >= 0){
        ady[n[i][j] - 'a'][n[i - 1][j] - 'a'] = 1;
        if(j - 1 >= 0) ady[n[i][j] - 'a'][n[i - 1][j - 1] - 'a'] = 1;
        if(j + 1 < n[i - 1].size()) ady[n[i][j] - 'a'][n[i - 1][j + 1] - 'a'] = 1;
      }
      if(i + 1 < 3){
        ady[n[i][j] - 'a'][n[i + 1][j] - 'a'] = 1;
        if(j - 1 >= 0) ady[n[i][j] - 'a'][n[i + 1][j - 1] - 'a'] = 1;
        if(j + 1 < n[i + 1].size()) ady[n[i][j] - 'a'][n[i + 1][j + 1] - 'a'] = 1;
      }
      
      if(j - 1 >= 0) ady[n[i][j] - 'a'][n[i][j - 1] - 'a'] = 1;
      if(j + 1 < n[i].size()) ady[n[i][j] - 'a'][n[i][j + 1] - 'a'] = 1;
    }
  }
  
  int t;
  cin >> t;
  string a, b;
  
  FOR(c, 0, t){
    cin >> a >> b;
    
    if(a == b){
      cout << "1\n";
    }else if(a.size() == b.size()){
      bool se = true;
      
      FOR(i, 0, a.size()){
        if(a[i] != b[i]){
          if(ady[a[i] - 'a'][b[i] - 'a'] == 0){
            se = false;
            break;
          }
        }
      }
      
      if(se) cout << "2\n";
      else cout << "3\n";
    }else{
      cout << "3\n";
    }
  }
  
  return 0;
}