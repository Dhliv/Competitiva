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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int n, p, pos;
  string ent;
  bool poss = false;
  cin >> n >> p >> ent;
  pos = p;
  vector<char> rep{'1', '0'};
  
  FOR(i, 0, n - p){
    if(ent[i] == ent[pos] and ent[i] == '.'){
      ent[i] = '0';
      ent[pos] = '1';
      poss = true;
      break;
    }else if(ent[i] == '.'){
      ent[i] = rep[ent[pos] - '0'];
      poss = true;
      break;
    }
    else if(ent[pos] == '.'){
      ent[pos] = rep[ent[i] - '0'];
      poss = true;
      break;
    }else if(ent[pos] != ent[i]){
      poss = true;
      break;
    }
    pos++;
  }
  
  if(poss){
    FOR(i, 0, n){
      if(ent[i] == '.') ent[i] = '0';
    }
    
    cout << ent + "\n";
  }else cout << "No\n";
  
  return 0;
}