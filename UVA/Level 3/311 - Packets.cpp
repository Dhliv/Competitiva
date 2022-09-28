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
 
using namespace std;

struct cajas{
	ll n1, n2, n3, n4, n5, n6;

	ll isCase(){
		return (n1 + n2 + n3 + n4 + n5 + n6);
	}
};

ll min(ll &a, ll &b){
	if(a < b) return a;
	return b;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n2, n3;
	cajas caja;
	ll ans;
	ll a, b, c, d, e, f, g, h, j;

	while(cin >> caja.n1 >> caja.n2 >> caja.n3 >> caja.n4 >> caja.n5 >> caja.n6, caja.isCase()){
		ans = caja.n6;

		if(caja.n5){
			ans += caja.n5;
			caja.n1 -= min(caja.n1, caja.n5*(6*6 - 5*5));
		}

		if(caja.n4){
			ans += caja.n4;
			a = caja.n4*5; // Cajas de 2 que caben en el resto de espacio.
			if(a >= caja.n2){
				a -= caja.n2;
				caja.n2 = 0;

				caja.n1 -= min(caja.n1, a*4);
			}else caja.n2 -= a;
		}

		if(caja.n3){
			ans += caja.n3/4;
			a = caja.n3%4;

			if(a){
				ans++;
				b = (7 - 2*a); // Numero de cajas 2*2 que caben en el espacio restante.
				c = 6*6 - 3*3*a - 2*2*b;
				if(b >= caja.n2){
					b -= caja.n2;
					caja.n2 = 0;

					caja.n1 -= min(caja.n1, b*4);
				}else caja.n2 -= b;

				caja.n1 -= min(caja.n1, c);
			}
		}

		if(caja.n2){
			ans += caja.n2/9;
			a = caja.n2%9;

			if(a){
				ans++;
				b = 6*6 - 2*2*a;

				caja.n1 -= min(caja.n1, b);
			}
		}

		if(caja.n1){
			ans += caja.n1/36;
			ans += (caja.n1%36 > 0 ? 1 : 0);
		}

		cout << ans << "\n";
	}
	
	return 0;
}