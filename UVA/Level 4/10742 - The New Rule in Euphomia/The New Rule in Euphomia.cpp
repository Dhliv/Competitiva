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

int datos = 1000000;
vector<int> all(datos+1, 1);

void criba(){
  FOR(i, 2, sqrt(datos) + 1){
    if(all[i]){
      for(int j = i*2; j <= datos; j+=i)
        all[j] = 0;
    }
  }
}

int findpos(vector<int> prims, int cant){
  int mid, low = 0, high = prims.size() - 1;
  
  while(low <= high){
    mid = (low + high)/2;
    if(prims[mid] > cant) high = mid - 1;
    else low = mid + 1;
  }
  
  return (low - 1);
}

int main() {
    vector<int> prims;
    int pos, cant, ans, aux, casos = 1;
    criba();
    
    FOR(i, 2, datos){
      if(all[i])
        prims.PB(i);
    }
    
    while(cin >> cant, cant){
      cout << "Case " << casos++ << ": ";
      pos = findpos(prims, cant);
      ans = 0;
      
      FOR(i, 0, pos + 1){
        if(prims[i] + prims[pos] <= cant){
          ans += pos - i;
        }else{
          i--;
          pos--;
        }
      }
      
      cout << ans << "\n";
    }

    return 0;
}