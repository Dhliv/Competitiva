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

double a, b, c, d, m, t;

double funcion(double v){
  double ans = a*pow(v, 3) + b*pow(v, 2) + c*v + d - t/m;
  return ans;
}

double bs(){
  double low = 0.0, high = INF*1.0, mid;

  FOR(i, 0, 100){
    mid = (low + high)/2;
    if(funcion(mid) >= 0.0) high = mid;
    else low = mid;
  }
  return (high + low)/2;
}

int main() {
  
  while(cin >> a >> b >> c >> d >> m >> t){
    cout.precision(2);
    
    cout << fixed << bs() - 0.005 << "\n";
  }

	return 0;
}