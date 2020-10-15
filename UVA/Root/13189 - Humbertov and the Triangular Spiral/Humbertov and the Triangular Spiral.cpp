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
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

pair<ll, int> look(ll n, vector<ll> &puntas){
  int low = 0, high = puntas.size(), mid;
  
  while(low <= high){
    mid = (high + low)/2;
    if(n <= puntas[mid]) high = mid - 1;
    else low = mid + 1;
  }
  
  return MP(puntas[low], low);
}

int main(){
  ll lim = 1000000000000, dif = 2;
  
  vector<ll> puntas;
  puntas.PB(1);
  puntas.PB(3);
  
  for(int i = 1; (puntas[i] + dif + 8) < (lim + 1); i++){
    dif += 8;
    puntas.PB(puntas[i] + dif);
  }
  puntas.PB(puntas[puntas.size() - 1] + dif + 8);
  
  int cases;
  pair<ll, int> datos;
  ll n, li, bb, lr, pt, pos;
  cin >> cases;
  vector<pair<int, int> > ans;
  
  ans.PB(MP(0, 0));
  ans.PB(MP(-1, 0));
  ans.PB(MP(0, 1));
  ans.PB(MP(1, 0));
  
  FOR(a, 0, cases){
    cin >> n;
    if(n <= 4){
      cout << ans[n - 1].f << " " << ans[n - 1].s << "\n";
      continue;
    }
    datos = look(n, puntas);
    pt = datos.f;
    pos = datos.s;
    li = pt - 2*pos;
    //cout << "punta: " << pt << " pos: " << pos << " ";
    if(n > li) cout << (n - pt) << " " << (pos - (pt - n)) << "\n";
    else{
      bb = li - (4*(pos - 1) + 2) + 1;
      if(n > bb) cout << (pt + 2 - n - 4*pos) << " " << (1 - pos) << "\n";
      else cout << (n + 8*pos - pt - 6) << " " << (pt - 7*pos - n + 5) << "\n";
    }
  }
  
  return 0;
}
