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

int main(){
  int palas, mayor, columnas, filas, ini, contador;
  string espa = "                                                            ";
  
  while(cin >> palas){
    cout << "------------------------------------------------------------\n";
    
    vector<string> v(palas);
    vector< vector<string> > orden;
    mayor = columnas = filas = contador = 0, ini = 60;
    
    FOR(i, 0, palas){
      cin >> v[i];
      if(v[i].size() > mayor)
        mayor = v[i].size();
    }
    
    ini -= mayor;
    columnas++;
    columnas += ini/(mayor+2);
    filas = palas/columnas;
    if(palas%columnas)
      filas++;
      
    sort(v.begin(), v.end());
    
    FOR(i, 0, filas){
      vector<string> aux;
      FOR(j, 0, columnas){
        if(j*filas + i < palas)
          aux.PB(v[j*filas + i]);
      }
      orden.PB(aux);
    }
    
    FOR(i, 0, orden.size()){
      FOR(j, 0, orden[i].size()){
        cout << orden[i][j] << espa.substr(0, mayor - orden[i][j].size());
        if(j+1 != orden[i].size())
          cout << "  ";
      }
      cout << "\n";
    }
    
    
  }
  
  return 0;
}