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

int binser(vector<int> mar, int tam, int x){
  int low = 0, high = tam-1, mid;
  
  while(low <= high){
    mid = (low + high)/2;
    if(mar[mid] >= x) high = mid - 1;
    else low = mid + 1;
  }
  
  return low;
}

int main(){
  int n, q, quer, cont = 1, pos;
  
  while(cin >> n >> q, n+q){
    cout << "CASE# " << cont++ << ":\n";
    vector<int> mar(n);
    FOR(i, 0, n)
      cin >> mar[i];
    
    sort(mar.begin(), mar.end());
    
    FOR(i, 0, q){
      cin >> quer;
      pos = binser(mar, n, quer);
      if(mar[pos] == quer)
        cout << quer << " found at " << pos+1 << "\n";
      else
        cout << quer << " not found\n";
    }
  }
  
  return 0;
}