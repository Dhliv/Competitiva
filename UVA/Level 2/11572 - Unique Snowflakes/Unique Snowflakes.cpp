#include <bits/stdc++.h>
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
typedef map<ll,int> mapa;

int main() {
	ll cases, num, aux, max, bef, aft;
	bool add;
	
	cin >> cases;
	
	FOR(a, 0, cases){
	  cin >> num;
	  mapa leMape;
	  vector< pair<ll, ll> > pos;
	  max = 0;
	  pos.PB(MP(0, 0));
	  
	  FOR(i, 0, num){
	    cin >> aux;
	    if(leMape.find(aux) == leMape.end())
	      leMape.insert(MP(aux,i));
	    else{
	      bef = pos.B().second;
	      aft = (leMape.find(aux)->second) + 1;
	      if(aft < bef)
	        pos.PB(MP(i, bef));
	      else
	        pos.PB(MP(i, aft));
	      leMape[aux] = i;
	    }
	  }
	  
	  pos.PB(MP(num, 0));
	  
	  FOR(i, 1, pos.size()){
  	  if((pos[i].first - pos[i-1].second) > max)
  	    max = (pos[i].first - pos[i-1].second);
	  }
	  
	  cout << max << "\n";
	}
	
	return 0;
}
