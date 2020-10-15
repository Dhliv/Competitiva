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

bool vivo;

vector<string> eraseBoat(vector<string> v, int i, int j, int size, int dir){
  vector<string> aux = v;
  aux[i][j] = '.';
  if(i+1 < size and dir == 1 and (aux[i+1][j] == 'x' or aux[i+1][j] == '@')){
    if(aux[i+1][j] == 'x')
      vivo = true;
    aux = eraseBoat(aux, i+1, j, size, dir);
  }
    
  if(i-1 >= 0 and dir == 1 and (aux[i-1][j] == 'x' or aux[i-1][j] == '@')){
    if(aux[i-1][j] == 'x')
      vivo = true;
    aux = eraseBoat(aux, i-1, j, size, dir);
  }
    
  if(j+1 < size and dir == 0 and (aux[i][j+1] == 'x' or aux[i][j+1] == '@')){
    if(aux[i][j+1] == 'x')
      vivo = true;
    aux = eraseBoat(aux, i, j+1, size, dir);
  }
    
  if(j-1 >= 0 and dir == 0 and (aux[i][j-1] == 'x' or aux[i][j-1] == '@')){
    if(aux[i][j-1] == 'x')
      vivo = true;
    aux = eraseBoat(aux, i, j+1, size, dir);
  }
    
  return aux;
}

int finDir(vector<string> v, int i, int j, int size){
  int ver;
  
  if(i+1 < size and (v[i+1][j] == 'x' or v[i+1][j] == '@'))
    ver = 1;
  else if(i-1 >= 0 and (v[i-1][j] == 'x' or v[i-1][j] == '@'))
    ver = 1;
  else if(j+1 < size and (v[i][j+1] == 'x' or v[i][j+1] == '@'))
    ver = 0;
  else if(j-1 < size and (v[i][j-1] == 'x' or v[i][j-1] == '@'))
    ver = 0;
  else
    ver = -1;
  
  return ver;
}

int main() {
	int cases, N, boats, vertical;
	cin >> cases;
	
	FOR(n, 0, cases){
	  boats = 0;
	  cin >> N;
	  vector<string> v(N);
	  
	  FOR(i, 0, N)
	    cin >> v[i];
	    
	  FOR(i, 0, N){
	    FOR(j, 0, N){
	      vivo = false;
	      if(v[i][j] == 'x'){
	        boats++;
	        vertical = finDir(v, i, j, N);
	        if(vertical == 1 or vertical == 0)
	          v = eraseBoat(v, i, j, N, vertical);
	        
	      }else if(v[i][j] == '@'){
	        vertical = finDir(v, i, j, N);
	        if(vertical == 1 or vertical == 0)
	          v = eraseBoat(v, i, j, N, vertical);
	         
	        if(vivo)
	          boats++;
	      }
	    }
	  }
	  
	  cout << "Case " << n+1 << ": " << boats << "\n";
	}
	
	return 0;
}
