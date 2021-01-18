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
#define For(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

bool search(string text, deque<string> &bad) 
{
  for(int i = 0; i < bad.size(); i++){
    if(text.find(bad[i]) != -1)
      return true;
  }
  return false;
} 

int main() {
  int n,m;
  cin >> n>>m;
  string aux, cadena;
  bool p=true;
  deque<string> bad(n),rev;
  For(i,0,n){
    cin >> bad[i];
  }
  For(i,0,m){
    cin >> aux;
    For(j,0,aux.length()){
      if(aux[j] == '0') aux[j] = 'O';
      if(aux[j] == '1') aux[j] = 'L';
      if(aux[j] == '2') aux[j] = 'Z';
      if(aux[j] == '3') aux[j] = 'E';
      if(aux[j] == '5') aux[j] = 'S';
      if(aux[j] == '6') aux[j] = 'B';
      if(aux[j] == '7') aux[j] = 'T';
      if(aux[j] == '8') aux[j] = 'B';
    }
    rev.PB(aux);
  }
  
  For(i,0,m){
    p = search(rev.F(), bad);
    rev.P_F();
    
    if(p) cout << "INVALID" <<endl;
    else cout << "VALID" <<endl;
    p=true;
  }

  return 0;
}