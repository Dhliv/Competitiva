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

vector<int> z_function(string &s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t, n, pos, cnt;
  string a, b, s, id, dis = "haha#";
  bool sum;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    getline(cin, s);
    map<string, pair<string, ll> > env;
    
    FOR(i, 0, n){
      deque<string> p;
      sum = 0;
      getline(cin, s);
      s.PB(' ');
      pos = 0;
      FOR(j, 0, s.size()){
        if(isspace(s[j])){
          p.PB(s.substr(pos, j - pos));
          pos = j + 1;
        }
      }
      
      id = p[0];
      vector<int> z;
      if(p.size() == 3){ // Asignacion
        a = p[2];
        s = dis + a;
        z = z_function(s);
        cnt = 0;
        
        FOR(j, 5, s.size()) if(z[j] == 4) cnt++;
        env[id] = MP(a, cnt);
      }else{ // suma
        auto it1 = env.find(p[2]);
        auto it2 = env.find(p[4]);
        a = it1->s.f;
        b = it2->s.f;
        a = (a.size() > 3) ? a.substr(a.size() - 3) : a;
        b = (b.size() > 3) ? b.substr(0, 3) : b;
        s = dis + a + b;
        z = z_function(s);
        cnt = 0;
        
        FOR(j, 5, s.size()) if(z[j] == 4) cnt++;
        
        a = it1->s.f;
        b = it2->s.f;
        b = (b.size() > 3) ? b.substr(b.size() - 3) : b;
        a = (a.size() > 3) ? a.substr(0, 3) : a;
        env[id] = MP(a + b, it1->s.s + it2->s.s + cnt);
      }
    }
    
    cout << env[id].s << "\n";
  }
  
  return 0;
}