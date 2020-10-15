#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
 
using namespace std;

typedef map<vector<string>,int> mapa;

vector<string> t;
mapa leMape;
bool full;

bool tricky(vector<string> s){
  full = true;
  
  FOR(i, 0, 3){
    FOR(j, 0, 3){
      if(s[i][j] == '.')
        full = false;
    }
  }
  
  if(full) return true;
  else if(s[0][0] == s[1][1] && s[1][1] == s[2][2] && (s[0][0] == 'X' || s[0][0] == 'O'))//D1
    return true;
  else if(s[0][2] == s[1][1] && s[1][1] == s[2][0] && (s[0][2] == 'X' || s[0][2] == 'O'))//D2
    return true;
  else if(s[0][0] == s[0][1] && s[0][1] == s[0][2] && (s[0][2] == 'X' || s[0][2] == 'O'))//F1
    return true;
  else if(s[1][0] == s[1][1] && s[1][1] == s[1][2] && (s[1][2] == 'X' || s[1][2] == 'O'))//F2
    return true;
  else if(s[2][0] == s[2][1] && s[2][1] == s[2][2] && (s[2][2] == 'X' || s[2][2] == 'O'))//F3
    return true;
  else if(s[0][0] == s[1][0] && s[1][0] == s[2][0] && (s[0][0] == 'X' || s[0][0] == 'O'))//C1
    return true;
  else if(s[0][1] == s[1][1] && s[1][1] == s[2][1] && (s[0][1] == 'X' || s[0][1] == 'O'))//C2
    return true;
  else if(s[0][2] == s[1][2] && s[1][2] == s[2][2] && (s[2][2] == 'X' || s[2][2] == 'O'))//C3
    return true;
  else
    return false;
}

void all_phases(vector<string> s){
  leMape.insert(MP(s, 0));
  if(tricky(s)) return;
  else{ // RECURSIVIDAD
  
    int x, o;
    x = o = 0;
  
    FOR(i,0,3){
      FOR(j,0,3){
        if(s[i][j] == 'X') x++;
        else if(s[i][j] == 'O') o++;
      }
    }
  
    char k = (x > o ? 'O' : 'X');
    
    FOR(i, 0, 3){
      FOR(j, 0, 3){
        if(s[i][j] == '.'){
          s[i][j] = k;
          all_phases(s);
          s[i][j] = '.';
        }
      }
    }
  }
}

int main(){
  int cases, cont = 0;
  vector<string> aux(3), puntos(3);
  FOR(i, 0, 3)
    puntos[i] = "...";
  all_phases(puntos);
  cin >> cases;
  FOR(num, 0, cases){
    FOR(i, 0, 3)
      cin >> aux[i];
      
    if(leMape.find(aux) != leMape.end())
      cout << "yes\n";
    else
      cout << "no\n";
  }
  
  return 0;
}