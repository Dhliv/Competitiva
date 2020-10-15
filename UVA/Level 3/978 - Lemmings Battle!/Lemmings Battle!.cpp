#include <bits/stdc++.h>
#define LINF LLONG_MAX
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
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, bat, b, g, x, y;
  cin >> cases;
  
  FOR(a, 0, cases){
    if(a) cout << "\n";
    
    cin >> bat >> g >> b;
    priority_queue<int> blue, green;
    
    FOR(i, 0, g){
      cin >> x;
      green.push(x);
    }
    
    FOR(i, 0, b){
      cin >> x;
      blue.push(x);
    }
    
    while(!blue.empty() and !green.empty()){
      bat = min(bat, (int)min(blue.size(), green.size()));
      vector<int> blu(bat), gre(bat);
      FOR(i, 0, bat){
        gre[i] = green.top(), blu[i] = blue.top();
        green.pop();
        blue.pop();
      }
      
      FOR(i, 0, bat){
        if(gre[i] > blu[i]) green.push(gre[i] - blu[i]);
        else if(blu[i] > gre[i]) blue.push(blu[i] - gre[i]);
      }
    }
    
    if(!blue.empty()){
      cout << "blue wins\n";
      while(!blue.empty()){
        cout << blue.top() << "\n";
        blue.pop();
      }
    }else if(!green.empty()){
      cout << "green wins\n";
      while(!green.empty()){
        cout << green.top() << "\n";
        green.pop();
      }
    }else cout << "green and blue died\n";
  }
  
  return 0;
}