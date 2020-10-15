#include <bits/stdc++.h>
#define INF 1000000000
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

bool verificar(vector<string> campo, int pos, int tam){
  bool reto = true;
  if(pos == tam) return reto;
  else{
    //FILA
    FOR(i, 0, tam){
      if(campo[pos][i] == '1'){
        if(i+1 == tam or pos+1 == tam)
          campo[pos][i] = '0';
        else if(i+1 < tam and campo[pos][i+1] == '1')
          campo[pos][i] = '0';
        else if(pos+1 < tam and campo[pos+1][i] == '1')
          campo[pos][i] = '0';
        else{
          reto = false;
        }
      }
    }
    
    //COLUMNA
    
    FOR(i, 0, tam){
      if(campo[i][pos] == '1'){
        if(i+1 == tam or pos+1 == tam)
          campo[pos][i] = '0';
        else if(i+1 < tam and campo[i+1][pos] == '1')
          campo[pos][i] = '0';
        else if(pos+1 < tam and campo[i][pos+1] == '1')
          campo[pos][i] = '0';
        else{
          reto = false;
        }
      }
    }
    
    if(reto)
      reto = reto and verificar(campo, pos+1, tam);
    
    return reto;
  }
}

int main(){
  int cases, tam;
  string in;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> tam;
    vector<string> campo(tam);
    
    FOR(i, 0, tam)
      cin >> campo[i];
      
    if(verificar(campo, 0, tam))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  
  return 0;
}