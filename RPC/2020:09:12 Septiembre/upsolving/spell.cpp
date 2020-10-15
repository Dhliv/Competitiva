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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int n, d, cont, tam;
  cin >> n;
  string ent;
  bool able;
  
  set<string> words;
  vector<string> entrada(n);
  
  FOR(i, 0, n){
    cin >> ent;
    words.insert(ent);
    entrada[i] = ent;
  }
  
  cin >> d;
  
  FOR(i, 0, d){
    cin >> ent;
    cout << ent + "\n";
    if(words.find(ent) != words.end()) cout << "CORRECT\n";
    else{
      map<char, int> pres;
      able = false;
      
      FOR(k, 0, ent.size()){
        if(pres.find(ent[k]) == pres.end()) pres.insert(MP(ent[k], 1));
        else pres[ent[k]]++;
      }
      
      FOR(j, 0, n){
        //omision
        tam = ent.size() + 1;
        cont = 0;
        
        if(entrada[j].size() == tam){
          FOR(k, 0, tam){
            if(ent[cont] == entrada[j][k]) cont++;
          }
          
          if(cont == tam - 1){
            cout << "ONE LETTER OMITTED FROM " + entrada[j] + "\n";
            able = true;
          }
        }
      
        //added:
      
        tam = ent.size() - 1;
        cont = 0;
        
        if(tam == entrada[j].size()){
          tam += 1;
          FOR(k, 0, tam){
            if(ent[k] == entrada[j][cont]) cont++;
          }
          
          if(cont == tam - 1){
            cout << "ONE LETTER ADDED TO " + entrada[j] + "\n";
            able = true;
          }
        }
      
        //diferent
        tam = ent.size();
        cont = 0;
        
        if(tam == entrada[j].size()){
          FOR(k, 0, tam){
            if(cont < 2){
              if(entrada[j][k] != ent[k]) cont++;
            }else break;
          }
          
          if(cont == 1){
            cout << "ONE LETTER DIFFERENT FROM " + entrada[j] + "\n";
            able = true;
          }
      
          //transpos:
          cont = 0;
          map<char, int> aux2 = pres;
          
          FOR(k, 0, tam){
            if(cont < 3){
              if(entrada[j][k] != ent[k]) cont++;
              if(aux2.find(entrada[j][k]) == aux2.end()){
                cont = 5;
                break;
              }else{
                aux2[entrada[j][k]]--;
                if(!aux2[entrada[j][k]]) aux2.erase(entrada[j][k]);
              }
            }else break;
          }
          
          if(cont == 2){
            cout << "TWO LETTERS TRANSPOSED IN " + entrada[j] + "\n";
            able = true;
          }
        }
      }
      if(!able) cout << "UNKNOWN\n";
    }
    
    cout << "\n";
  }
  
  return 0;
}