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

bool comp(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b){
  return a.f < b.f;
}

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void com(int &a, int &b, vector<int> &p, vector<int> &s){
  if(s[a] < s[b]) swap(a, b);

  p[b] = a;
  s[a] += s[b];
  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, m, x, y, xf, yf, mini, c, smini, g, minx;
  bool pl;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> m;
    vector<int> p(n + 1), s(n + 1, 1);
    FOR(i, 1, n + 1) p[i] = i;

    deque<pair<int, pair<int, int> > > q;
    FOR(i, 0, m){
      cin >> x >> y >> c;
      q.PB(MP(c, MP(x, y)));
    }

    sort(q.begin(), q.end(), comp);

    deque<pair<int, pair<int, int> > > sl, nsl;
    mini = 0;
    g = n;
    FOR(i, 0, m){
      x = q[i].s.f;
      y = q[i].s.s;
      c = q[i].f;

      xf = find(x, p);
      yf = find(y, p);

      if(xf != yf){
        sl.PB(q[i]);
        mini += c;
        g--;
        com(xf, yf, p, s);
      }else nsl.PB(q[i]);
    }

    cout << "Case #" << ab + 1 << " : ";
    if(g > 1) cout << "No way\n";
    else if(nsl.empty()) cout << "No second way\n";
    else{
      smini = INF;

      FOR(i, 0, sl.size()){
        FOR(j, 1, n + 1){
          p[j] = j;
          s[j] = 1;
        }

        minx = mini - sl[i].f;
        FOR(j, 0, sl.size()){
          if(j == i) continue;
          xf = find(sl[j].s.f, p);
          yf = find(sl[j].s.s, p);
          com(xf, yf, p, s);
        }

        pl = 0;
        FOR(j, 0, nsl.size()){
          x = nsl[j].s.f;
          y = nsl[j].s.s;
          c = nsl[j].f;
          xf = find(x, p);
          yf = find(y, p);

          if(xf != yf){
            minx += c;
            pl = 1;
            break;
          }
        }

        if(pl) smini = min(minx, smini);
      }

      cout << smini << "\n";
    }
  }

  return 0;
}
