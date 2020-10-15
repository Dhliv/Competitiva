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

int main() {
  int fil,col, cFil,cCol, contador=0, cAux;
  string orden1="", orden2="";
  

  cin>>fil>>col>>cFil>>cCol;
  deque<int> tam(cFil);
  For(i,0,cFil){
    cin >> tam[i];
  }
  For(i,0,cCol){
    cin>>cAux;
    For(j,0,cAux){
      if(contador%2){
        orden1+="W";
        orden2+="B";
        }
      else{
        orden1+="B";
        orden2+="W";
      }
    }
    contador++;
  }
  contador =0;
  
  while(tam.size()){
    int aux = tam.F();
    tam.P_F();
      For(i,0,aux){
        if(contador%2) cout << orden2<<endl;
        else cout << orden1<<endl;
      }
      contador++;
  }
 

  return 0;
}