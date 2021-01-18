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
	string n,m, aux;
	map<string, int> s;
	cin >>n>>m;
	s.insert(MP(m, 0));
	
	For(i,0,m.length()){
	    aux=m;
	    aux.erase(i,1);
	    s.insert(MP(aux, 0));
	}

	For(i,0,m.length()){
	    For(j,0,n.length()){
          aux = m;
          aux.insert(i, 1, n[j]);
	        s.insert(MP(aux, 0));
	    }
	}
  
	For(i,0,n.length())
	{
	  aux = m+n[i];
	  s.insert(MP(aux, 0));
	}

	For(i,0,m.length()){
	  aux = m;
	  For(j,0,n.length()){
	    aux[i] = n[j];
	    s.insert(MP(aux, 0));
	  }
	}
	
	if(s.find(m) != s.end())
	  s.erase(m);

	forit(i,s){
	  cout << i->first << endl;
	}
	return 0;
}