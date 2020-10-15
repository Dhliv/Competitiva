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

bool asc(string a, string b){
  string apa, apb;
  apa = a + b;
  apb = b + a;

  return apa > apb;
}

int main(){
  int N;
  
  while(cin >> N, N){
    vector<string> v(N);
    
    FOR(i, 0, N)
      cin >> v[i];
      
    sort(v.begin(), v.end(), asc);
    
    FOR(i, 0, N)
      cout << v[i];
      
    cout << "\n";
    
  }
  
  return 0;
}