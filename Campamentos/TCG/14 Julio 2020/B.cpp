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
int dato = 1000010;
vector<int> np(dato);

void cola(){
  FOR(i, 2, sqrt(dato) + 1){
    if(np[i] == 0){
      for(int j = 2*i; j < dato; j += i) np[j] = 1;
    }
  }
}

int main(){
  int n;
  cin >> n;
  cola();
  
  FOR(i, 1, 1001){
    if(np[n*i + 1]){
      cout << i << "\n";
      break;
    }
  }
  
  return 0;
}