#include <bits/stdc++.h>
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
typedef map<string,int> mapa;
typedef deque<char> DQ;

mapa leMape;

void io(DQ actual, DQ original, DQ target, string impresion){
  string res = impresion;
  if(original.empty() and target.empty()){
    leMape.insert(MP(res.substr(0, res.size()-1), 0));
    return; //ALMACENAR
  }
  
  if(actual.size()){

    if(actual.B() == target.F()){
      char aux = target.F();
      char aux2 = actual.B();
      target.P_F();
      actual.P_B();
      io(actual, original, target, res+"o ");
      
      target.PF(aux);
      actual.PB(aux2);
      if(original.size()){
        actual.PB(original.F());
        original.P_F();
        res += "i ";
        io(actual, original, target, res);
      }
    }else if(original.size()){
      actual.PB(original.F());
      original.P_F();
      res += "i ";
      io(actual, original, target, res);
    }else
      return; //COMBINACION MALA
  }
  else if(original.size()){
    actual.PB(original.F());
    original.P_F();
    res += "i ";
    io(actual, original, target, res);
  }
}


int main() {
	string a1, a2;
	DQ original, actual, target;
	
	while(cin >> a1 >> a2){
	  cout << "[\n";
    if(a1.size() == a2.size()){

      FOR(i, 0, a1.size())
        original.PB(a1[i]);
      
      FOR(i, 0, a2.size())
        target.PB(a2[i]);
	    
      io(actual, original, target, "");
      
      forit(x, leMape)
        cout << x->first << "\n";
        
      leMape.clear();

      original.clear();
      actual.clear();
      target.clear();
    }
    cout << "]\n";
	}
	
	return 0;
}
