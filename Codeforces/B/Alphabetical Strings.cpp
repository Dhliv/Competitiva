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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, l, r, n, step;
  cin >> t;
  string s;
  bool able;
  const char a = 'a';

  FOR(ab, 0, t){
    cin >> s;
    n = s.size();
    vector<int> v(26);
    able = true;

    FOR(i, 0, s.size()){
      if(s[i] == a) l = i;
      v[s[i] - a]++;
    }

    FOR(i, 0, n) if(v[i] != 1) able = false;

    if(!able) cout << "No\n";
    else{
      r = l + 1;
      l--;
      step = 1;

      while(l >= 0 and r < n){
        if(s[l] == a + step){
          l--;
          step++;
        }else if(s[r] == a + step){
          r++;
          step++;
        }else{
          able = false;
          break;
        }
      }

      while(l >= 0){
        if(s[l] == a + step){
          l--;
          step++;
        }else{
          able = false;
          break;
        }
      }

      while(r < n){
        if(s[r] == a + step){
          r++;
          step++;
        }else{
          able = false;
          break;
        }
      }

      if(able) cout << "Yes\n";
      else cout << "No\n";
    }
  }

  return 0;
}