#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
 
using namespace std;

int comp(string &a, string &b){
	if(a.size() > b.size()) return 1;
	if(a.size() < b.size()) return -1;

	FOR(i, 0, a.size()){
		if(a[i] != b[i]){
			if(a[i] < b[i]) return -1;
			return 1;
		}
	}

	return 0;
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string a, b;
  int na, nb, t;
  cin >> t;

  FOR(ab, 0, t){
  	cin >> a >> na;
  	cin >> b >> nb;

  	int ans;
  	if(a.size() + na < b.size() + nb) ans = -1;
  	else if(a.size() + na > b.size() + nb) ans = 1;
  	else{
  		if(a.size() < b.size()) FOR(i, a.size(), b.size()) a.PB('0');
  		else FOR(i, b.size(), a.size()) b.PB('0');
  		ans = comp(a, b);
  	}
  	
  	if(ans == -1) cout << "<\n";
  	else if(ans == 0) cout << "=\n";
  	else cout << ">\n";
  }
  
  return 0;
}