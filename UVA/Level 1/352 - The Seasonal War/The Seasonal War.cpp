#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define MP make_pair
#define For(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

typedef stack<int> st;
typedef map<ll,int> mapa;

vector<int> resultados;

void recorrer(pair<int,int> pos, vector<string> &arr, int eagle, int tam){

  if(arr[pos.first][pos.second] == '1')
  {
    arr[pos.first][pos.second] = '0';
    if(pos.first+1 < tam && pos.second+1<tam) recorrer(MP(pos.first+1,pos.second+1), arr, eagle, tam);
    if(pos.first+1 < tam) recorrer(MP(pos.first+1,pos.second), arr, eagle, tam);
    if(pos.first+1 < tam && -1 < pos.second-1) recorrer(MP(pos.first+1,pos.second-1), arr, eagle, tam);
    if(tam > pos.second+1) recorrer(MP(pos.first,pos.second+1), arr, eagle, tam);
    if(pos.second-1>-1) recorrer(MP(pos.first,pos.second-1), arr, eagle, tam);
    if(pos.first-1 >-1 && pos.second+1 < tam) recorrer(MP(pos.first-1,pos.second+1), arr, eagle, tam);
    if(pos.first-1 >-1) recorrer(MP(pos.first-1,pos.second), arr, eagle, tam);
    if(pos.first-1> -1 && pos.second-1 >-1) recorrer(MP(pos.first-1,pos.second-1), arr, eagle, tam);
  }else return;
  
  return;
}

int main(){
  int tam, eagle, cases = 1;
  while(cin >> tam){
    vector<string> arr(tam);
    eagle = 0;
    For(i,0,tam){
      cin >> arr[i];
    }
    For(i,0,tam){
      For(j,0,tam){
        if(arr[i][j] == '1'){
          eagle++;
          recorrer(MP(i, j), arr, eagle, tam);
        }
      }
    }
    cout << "Image number " << cases << " contains " << eagle << " war eagles.\n";
    cases++;
  }

  return 0;
}