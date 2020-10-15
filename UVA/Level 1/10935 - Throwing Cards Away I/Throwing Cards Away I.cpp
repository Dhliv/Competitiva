#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <math.h>
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
 
using namespace std;

typedef deque<int> DQ;
typedef map<int,int> mapa;

int main()
{
  int cards, aux;
  DQ descarted, deck;
  
  while(cin >> cards, cards){
    FOR(i, 0, cards)
      deck.PB(i+1);
      
    while(deck.size() > 1){
      descarted.PB(deck.F());
      deck.P_F();
      deck.PB(deck.F());
      deck.P_F();
    }
    aux = descarted.size();
    cout << "Discarded cards:";
    FOR(i, 0, aux){
      if(i+1 == aux)
        cout << " " << descarted.F();
      else{
        cout << " " << descarted.F() << ",";
        descarted.P_F();
      }
    }
    
    cout << "\nRemaining card: " << deck.F() << "\n";
    descarted.clear();
    deck.clear();
  }
  return 0;
}