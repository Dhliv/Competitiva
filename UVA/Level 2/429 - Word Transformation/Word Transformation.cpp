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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, cont, tam, posI, posF, nodo, leng;
  string ini, fin;
  cin >> cases;
  getline(cin, ini);
  getline(cin, ini);
  
  FOR(a, 0, cases){
    if(a)
      cout << "\n";
    
    vector<vector<string> > diccionario(11);
    vector<vector<vector<int> > > grafo(11);
    
    while(getline(cin, ini), ini != "*")
      diccionario[ini.size()].PB(ini);
      
    //Hacer grafo:
    
    FOR(i, 2, 11){
      cont = diccionario[i].size();
      vector<vector<int> > aux(cont);
      grafo[i] = aux;
    }
    
    FOR(lon, 2, 11){
      FOR(i, 0, grafo[lon].size()){
        ini = diccionario[lon][i];
        FOR(j, i+1, grafo[lon].size()){
          cont = 0;
          fin = diccionario[lon][j];
          
          FOR(pos, 0, lon){
            if(ini[pos] != fin[pos])
              cont++;
          }
          
          if(cont <= 1){
            grafo[lon][i].PB(j);
            grafo[lon][j].PB(i);
          }
        }
      }
    }
    
    //FIN del grafo.
      
    while(getline(cin, ini)){
      
      if(ini.size() == 0) break;
      
      FOR(i, 0, ini.size()){
        if(isspace(ini[i])){
          fin = ini.substr(i+1, ini.size() - (i+1));
          ini = ini.substr(0, i);
          break;
        }
      }
      leng = ini.size();
      
      if(ini == fin) cout << ini + " " + fin + " " << 0 << "\n";
      else if(leng >= 2){
        tam = diccionario[leng].size();
        vector<int> dist(tam, INF);
        
        FOR(i, 0, tam){
          if(ini == diccionario[leng][i])
            posI = i;
          else if(fin == diccionario[leng][i])
            posF = i;
        }
        
        deque<int> dq;
        dist[posI] = 0;
        dq.PB(posI);
        
        while(!dq.empty()){
          nodo = dq.F();
          dq.P_F();
          
          FOR(i, 0, grafo[leng][nodo].size()){
            if(dist[grafo[leng][nodo][i]] == INF){
              dist[grafo[leng][nodo][i]] = 1 + dist[nodo];
              dq.PB(grafo[leng][nodo][i]);
            }
          }
        }
        
        cout << ini + " " + fin + " " << dist[posF] << "\n";
      }else
        cout << ini + " " + fin + " " << 1 << "\n";
    }
  }

  return 0;
}