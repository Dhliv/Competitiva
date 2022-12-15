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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

struct st{
  int l, r, m, maxi, h, mini;
  st *left, *right;
  bool lazy;

  void com(){
    maxi = max(left->maxi, right->maxi);
    mini = min(left->mini, right->mini);
  }

  st(int l, int r){
    this->l = l;
    this->r = r;
    mini = maxi = h = lazy = 0;

    if(l != r){
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
    }
  }

  void pro(){
    lazy = 0;

    if(l != r){
      left->mini = left->maxi = h;
      left->h = h;
      left->lazy = 1;

      right->mini = right->maxi = h;
      right->h = h;
      right->lazy = 1;
    }

    h = 0;
  }

  void up(int &i, int &j, int &x){
    if(lazy) pro();

    if(j < l or i > r or x < mini) return;
    if(i <= l and r <= j and x >= maxi){
      mini = maxi = x;
      h = x;
      lazy = 1;
      return;
    }

    left->up(i, j, x);
    right->up(i, j, x);
    com();
  }

  int get(int i){
    if(lazy) pro();

    if(l == r) return maxi;
    if(i <= m) return left->get(i);
    return right->get(i);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //ifstream cin("in.txt");

  st tr(0, 10000);
  int l, r, h;
  int mini = INF, maxi = -1;
  while(cin >> l >> h >> r){
    r--;
    tr.up(l, r, h);
    mini = min(mini, l);
    maxi = max(maxi, r + 1);
  }

  int last = tr.get(mini), act;
  cout << "1 " << last << " ";
  FOR(i, mini + 1, maxi){
    act = tr.get(i);
    if(act != last){
      cout<< i << " " << act << " ";
      last = act;
    }
  }

  cout << maxi << " 0\n";

  return 0;
}