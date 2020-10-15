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

vector<int> zf(string s) {
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
  int cases, len, best, pos, val;
  string ent, aux;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> aux;
    vector<int> s;
    best = MINF;
    
    ent = aux;
    reverse(aux.begin(), aux.end());
    
    s = zf(ent + "#" + aux);
    len = ent.size()*2 + 1;
    val = ent.size() + 1;
    
    FOR(i, val, len){
      if(s[i] > best){
        best = s[i];
        pos = i - val;
      }
    }
    
    ent = aux.substr(pos, best);
    reverse(ent.begin(), ent.end());
    
    cout << ent << "\n";
  }
  
  return 0;
}
