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

typedef deque<pair<int, bool> > DQ;
typedef map<int,int> mapa;

int main()
{
  int cases, jobs, mine, aux, mins, search, pos;
  DQ newOne, dq;
  cin >> cases;
  FOR(num, 0, cases){
    cin >> jobs >> mine;
    int prio[10] = {0};
    mins = 0;
    pos = 0;
    
    FOR(i, 0, jobs){
      cin >> aux;
      prio[aux] += 1;
      if(mine == i){
        dq.PB(make_pair(aux, true));
        search = aux;
      }
      else
        dq.PB(make_pair(aux,false));
    }
    
    for(int i = 9; i > 0; i--){
      if(search == i)
        break;
      else{
        mins += prio[i];
        if(prio[i]){
          FOR(j, 0, dq.size()){
            if(dq[dq.size()-j-1].first == i){
              pos = dq.size() - j;
              break;
            }
          }
          
          FOR(j, pos, dq.size())
            newOne.PB(dq[j]);
            
          FOR(j, 0, pos){
            if(dq[j].first != i)
              newOne.PB(dq[j]);
          }
          
          dq.swap(newOne);
          newOne.clear();
        }
        prio[i] = 0;
      }
    }
    
    FOR(i, 0, dq.size()){
      if(dq[i].first == search){
        mins++;
        if(dq[i].second)
          break;
      }
    }
    dq.clear();
    cout << mins << "\n";
  }
  
  return 0;
}