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

bool comp(char a, char b){
  return a > b;
}

int main(){
  string ent;
  char k;
  cin >> ent;
  
  sort(ent.begin(), ent.end(), comp);
  
  FOR(i, 0, ent.size() - 1){
    if(ent[i] == ent[i+1] and ent[i] != 'z'){
      k = ent[i]+1;
      ent.insert(i+2, 1, k);
      ent.erase(i, 2);
      if(i > 0)
        i-=2;
      else
        i--;
    }
  }
  
  cout << ent + "\n";
  
  return 0;
}