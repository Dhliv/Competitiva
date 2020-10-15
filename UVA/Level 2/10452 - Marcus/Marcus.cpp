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
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;
string alias = "IEHOVA#";

void impr(vector<string> v, int i, int j, int pos, int anch, int larg){
  if(pos+1 == alias.size()){
    if(j-1 >= 0 and v[i][j-1] == alias[pos])
      cout << "left\n";
    else if(j+1 < larg and v[i][j+1] == alias[pos])
      cout << "right\n";
    else
      cout << "forth\n";
      
    return;
  }
  
  if(j-1 >= 0 and v[i][j-1] == alias[pos]){
    cout << "left ";
    impr(v, i, j-1, pos+1, anch, larg);
  }
  else if(j+1 < larg and v[i][j+1] == alias[pos]){
    cout << "right ";
    impr(v, i, j+1, pos+1, anch, larg);
  }
  else{
    cout << "forth ";
    impr(v, i-1, j, pos+1, anch, larg);
  }
  
}

int main() {
	int anch, larg, cases;
	cin >> cases;
	
	FOR(num, 0, cases){
    cin >> anch >> larg;
    vector<string> v(anch);
    
    FOR(i, 0, anch)
      cin >> v[i];
      
    FOR(i, 0, anch){
      FOR(j, 0, larg){
        if(v[i][j] == '@')
          impr(v, i, j, 0, anch, larg);
      }
    }
	}
	
	return 0;
}
