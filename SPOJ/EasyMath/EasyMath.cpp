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

ll findN(ll dat[5], ll m){
  ll added, aux;
  added = m/dat[0] + m/dat[1] + m/dat[2] + m/dat[3] + m/dat[4];
  
  //Intersecciones Dobles:
  
  FOR(i,0,5){
    FOR(j,i+1,5){
      added -= m/((dat[i]*dat[j])/__gcd(dat[i], dat[j]));
    }
  }
  
  /*
  ////Interseccion con el 1:
  added -= m/((dat[0]*dat[1])/__gcd(dat[0], dat[1]));
  added -= m/((dat[0]*dat[2])/__gcd(dat[0], dat[2]));
  added -= m/((dat[0]*dat[3])/__gcd(dat[0], dat[3]));
  added -= m/((dat[0]*dat[4])/__gcd(dat[0], dat[4]));
  
  ////Interseccion con el 2:
  added -= m/((dat[1]*dat[2])/__gcd(dat[1], dat[2]));
  added -= m/((dat[1]*dat[3])/__gcd(dat[1], dat[3]));
  added -= m/((dat[1]*dat[4])/__gcd(dat[1], dat[4]));
  
  ////Interseccion con el 3:
  added -= m/((dat[2]*dat[3])/__gcd(dat[2], dat[3]));
  added -= m/((dat[2]*dat[4])/__gcd(dat[2], dat[4]));
  
  ////Interseccion con el 4:
  added -= m/((dat[3]*dat[4])/__gcd(dat[3], dat[4]));*/
  
  
  FOR(i,0,5){
    FOR(j,i+1,5){
      aux = ((dat[i]*dat[j])/__gcd(dat[i], dat[j]));
      FOR(k,j+1,5){
        added += m/((aux*dat[k])/__gcd(aux, dat[k]));
      }
    }
  }
  /*
  //Intersecciones Triples:
  
  ////Interseccion con el 1:
  aux = (dat[0]*dat[1])/__gcd(dat[0], dat[1]);
  added += m/((aux*dat[2])/__gcd(aux, dat[2]));
  aux = (dat[0]*dat[1])/__gcd(dat[0], dat[1]);
  added += m/((aux*dat[3])/__gcd(aux, dat[3]));
  aux = (dat[0]*dat[1])/__gcd(dat[0], dat[1]);
  added += m/((aux*dat[4])/__gcd(aux, dat[4]));
  
  aux = (dat[0]*dat[2])/__gcd(dat[0], dat[2]);
  added += m/((aux*dat[3])/__gcd(aux, dat[3]));
  aux = (dat[0]*dat[2])/__gcd(dat[0], dat[2]);
  added += m/((aux*dat[4])/__gcd(aux, dat[4]));
  
  aux = (dat[0]*dat[3])/__gcd(dat[0], dat[3]);
  added += m/((aux*dat[4])/__gcd(aux, dat[4])); //6 elementos
  
  
  ////Interseccion con el 2:
  aux = (dat[1]*dat[2])/__gcd(dat[1], dat[2]);
  added += m/((aux*dat[3])/__gcd(aux, dat[3]));
  aux = (dat[1]*dat[2])/__gcd(dat[1], dat[2]);
  added += m/((aux*dat[4])/__gcd(aux, dat[4]));
  
  aux = (dat[1]*dat[3])/__gcd(dat[1], dat[3]);
  added += m/((aux*dat[4])/__gcd(aux, dat[4]));//3 elementos
  
  
  ////Interseccion con el 3:
  aux = (dat[2]*dat[3])/__gcd(dat[2], dat[3]);
  added += m/((aux*dat[4])/__gcd(aux, dat[4]));//1 elemento*/
  
  
  
  
  FOR(i,0,5){
    FOR(j,i+1,5){
      aux = ((dat[i]*dat[j])/__gcd(dat[i], dat[j]));
      FOR(k,j+1,5){
        aux = (aux*dat[k])/__gcd(aux, dat[k]);
        FOR(ab,k+1,5){
          added -= m/((aux*dat[ab])/__gcd(aux, dat[ab]));
        }
      }
    }
  }
  /*
  //Intersecciones Cuadruples:
  aux = (dat[0]*dat[1])/__gcd(dat[0], dat[1]);
  aux = (aux*dat[2])/__gcd(aux, dat[2]);
  added -= m/((aux*dat[3])/__gcd(aux, dat[3]));
  
  aux = (dat[1]*dat[2])/__gcd(dat[1], dat[2]);
  aux = (aux*dat[3])/__gcd(aux, dat[3]);
  added -= m/((aux*dat[4])/__gcd(aux, dat[4]));
  
  aux = (dat[2]*dat[3])/__gcd(dat[2], dat[3]);
  aux = (aux*dat[4])/__gcd(aux, dat[4]);
  added -= m/((aux*dat[0])/__gcd(aux, dat[0]));
  
  aux = (dat[3]*dat[4])/__gcd(dat[3], dat[4]);
  aux = (aux*dat[0])/__gcd(aux, dat[0]);
  added -= m/((aux*dat[1])/__gcd(aux, dat[1]));
  
  aux = (dat[4]*dat[0])/__gcd(dat[4], dat[0]);
  aux = (aux*dat[1])/__gcd(aux, dat[1]);
  added -= m/((aux*dat[2])/__gcd(aux, dat[2]));*/
  
  //Interseccion de todos:
  
  aux = (dat[0]*dat[1])/__gcd(dat[0], dat[1]);
  aux = (aux*dat[2])/__gcd(aux, dat[2]);
  aux = (aux*dat[3])/__gcd(aux, dat[3]);
  added += m/((aux*dat[4])/__gcd(aux, dat[4]));
  
  return added;
}

int main() {
	ll cases, n, m, a, d;
	cin >> cases;
	
	FOR(i, 0, cases){
	  cin >> n >> m >> a >> d;
	  ll dat[5], resm = m, resn = n-1, res;
	  
	  FOR(i, 0, 5)
	    dat[i] = a + i*d;
	  
	  resm -= findN(dat, m);
	  resn -= findN(dat, n-1);
	  res = resm - resn;
	  
	  cout << res << "\n";
	}
	
	return 0;
}
