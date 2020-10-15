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
	string a1, a2;
	
	while(cin >> a1){
	  cin >> a2;
	  ll res[600] = {0};
	  
	  reverse(a1.begin(), a1.end());
	  reverse(a2.begin(), a2.end());
	  
	  FOR(i, 0, a1.size()){
	    FOR(j, 0, a2.size()){
	      res[i+j] += (a1[i] - '0')*(a2[j] - '0');
	    }
	  }
	  
	  FOR(i, 0, 600-1){
	    res[i+1] += res[i]/10;
	    res[i] = res[i]%10;
	  }
	  
	  for(int i = 600-1; i >= 0; i--){
	    if(res[i] or i == 0){
	      for(int j = i; j >= 0; j--)
	        cout << res[j];
	      break;
	    }
	  }
	  cout << "\n";
	}
	
	return 0;
}
