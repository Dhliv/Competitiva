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

double dist(int x1, int x2, int y1, int y2, int z1, int z2){
  double d = sqrt(pow((x1-x2), 2)+pow((y1-y2), 2)+pow((z1-z2), 2));
  return d;
}

int main() {
  int cases, planets, worms, x, y, z, quers, nodo;
  ll ans;
  string name, ori, dest;
  
  cin >> cases;

  FOR(a, 0, cases){
    cout << "Case " << a+1 << ":\n";
    cin >> planets;
    vector<vector<double> > ady(planets, vector<double> (planets));
    vector<pair<int, pair<int, int> > > coords(planets);
    map<string, int> names;

    FOR(i, 0, planets){
      cin >> name >> x >> y >> z;
      names[name] = i;
      coords[i] = MP(x, MP(y, z));
    }
    
    FOR(i, 0, planets){
      for(int j = 0; j < planets; j++){
        if(j == i) continue;
        ady[i][j] = dist(coords[i].f, coords[j].f, coords[i].s.f, coords[j].s.f, coords[i].s.s, coords[j].s.s);
      }
    }
    cin >> worms;

    FOR(i, 0, worms){
      cin >> ori >> dest;
      ady[names[ori]][names[dest]] = 0;
    }
    
    cin >> quers;
    
    FOR(b, 0, quers){
      cin >> ori >> dest;
      nodo = names[ori];
      priority_queue<pair<long double, int> > pq;
      pq.push(MP(0.0, nodo));
      vector<int> visit(planets);
      vector<long double> seen(planets, INF);
      seen[nodo] = 0;

      while(!pq.empty()){
        nodo = pq.top().s;
        pq.pop();

        if(visit[nodo]) continue;
        visit[nodo] = 1;

        for(int i = 0; i < planets; i++){
          if(visit[i] or i == nodo) continue;
          if(seen[i] > seen[nodo] + ady[nodo][i]){
            seen[i] = seen[nodo] + ady[nodo][i];
            pq.push(MP(-seen[i], i));
          }
        }
      }
      ans = round(seen[names[dest]]);
      cout << "The distance from " + ori + " to " + dest + " is ";
      cout << ans << " parsecs.\n";
    }

  }
	return 0;
}