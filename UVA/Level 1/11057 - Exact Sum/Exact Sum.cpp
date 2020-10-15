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

int p;

bool bs(int pos, int val, vector<int> &v){
  int low = 0, high = v.size() - 1, mid;
  
  while(low <= high){
    mid = (low + high)/2;
    if(val >= v[mid]) low = mid + 1;
    else high = mid - 1;
  }
  
  if(val == v[high] and pos != high)
    return true;
  else
    return false;
}

int main() {
	int n, aux, ans, a, b;
	
	while(cin >> n){
  	vector<int> v(n);
  	ans = INF, a = b = 0;
  	
  	FOR(i, 0, n)
  	  cin >> v[i];
  	cin >> p;
  	  
  	sort(v.begin(), v.end());
  	
  	FOR(i, 0, n-1){
  	  if(p - v[i] < 0) break;
  	  if(ans > abs(p - 2*v[i]) and bs(i, p - v[i], v)){
  	    ans = abs(p - 2*v[i]);
  	    a = v[i], b = p - v[i];
  	  }
  	}
  	cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
	}
	
	return 0;
}