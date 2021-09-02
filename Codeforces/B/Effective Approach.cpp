#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    long long int orden = 0, inverso = 0, elementos, busquedas, aux, neoAux;
    map<int, int> leMape;
    cin >> elementos;
    
    for(int i = 1; i <= elementos; i++){
        cin >> aux;
        leMape.insert(pair<int, int>(aux, i));
    }
    
    cin >> busquedas;
    
    for(int i = 0; i < busquedas; i++){
        cin >> aux;
        neoAux = leMape.find(aux)->second;
        orden += neoAux;
        inverso += elementos-neoAux+1;
    }
    
    cout << orden << " " << inverso;

    return 0;
}
