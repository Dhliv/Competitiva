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

typedef deque<pair<int,int> > DQ;
typedef map<int,int> mapa;

int main()
{
  int cases, autos, cruzar, comms, mins, arrive, aux;
  string dir;
  bool izq;
  DQ left, right;
  cin >> cases;

  FOR(num, 0, cases){
    cin >> autos >> cruzar >> comms;
    mins = 0;
    int impri[comms];
    izq = true;
    FOR(i, 0, comms){
      cin >> arrive >> dir;
      if(dir == "left"){
        left.PB(make_pair(arrive, i));
      }
      else{
        right.PB(make_pair(arrive, i));
      }
    }

    while(!left.empty() || !right.empty()){
      if(left.empty() and right.F().first > mins){
        mins = right.F().first;
      }else if(right.empty() and left.F().first > mins){
        mins = left.F().first;
      }else if(!left.empty() and !right.empty()){
        if(left.F().first > mins and right.F().first > mins)
          mins = min(left.F().first, right.F().first);
      }
          
      if(izq){
        aux = left.size();
        FOR(j, 0, aux){
          if(j < autos && left.F().first <= mins){
            impri[left.F().second] = mins + cruzar;
            left.P_F();
          }
          else
            break;
        }
        mins += cruzar;
        izq = false;
      }else{
        aux = right.size();
        FOR(j, 0, aux){
          if(j < autos && right.F().first <= mins){
            impri[right.F().second] = mins + cruzar;
            right.P_F();
          }else
            break;
        }
        mins += cruzar;
        izq = true;
      }
    }
    
    FOR(j, 0, comms)
      cout << impri[j] << "\n";
    
    if(num+1 < cases) cout << "\n";
  }
  return 0;
}