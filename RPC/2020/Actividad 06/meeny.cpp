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
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
using namespace std;

int main() {
	ll cont=0,n;
  int sig=0;
  string s,aux;
  deque<string> v;
  vector<vector<string>> eq(2);
  getline(cin, s);
  For(i,0,s.length()){
    if(s[i] == ' ') cont++;
  }
  
  cin >>n;
  For(i,0,n){
    cin >>aux;
    v.PB(aux);
  }
  
  while(v.size()){
    
    For(i,0,cont){
      aux = v.F();
      v.P_F();
      v.PB(aux);
    }
    eq[sig].PB(v.F());
    v.P_F();
    sig= (sig+1)%2;
  }
  For(i,0,2){
    cout << eq[i].size()<<endl;
    For(j,0,eq[i].size()){
      cout << eq[i][j]<<endl;
    }
  }
  
	return 0;
}
