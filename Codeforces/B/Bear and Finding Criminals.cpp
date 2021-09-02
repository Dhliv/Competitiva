#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    int contDer, contIzq, ciudades, cop, maxDistancia, ladrones = 0;
    bool izq = false, der = false;
    cin >> ciudades >> cop;
    int criminales[ciudades];
    
    for(int i = 0; i < ciudades; i++){
        cin >> criminales[i];
    }
    
    maxDistancia = ciudades - cop;
    
    if(cop > maxDistancia)
        maxDistancia = cop;
    
    contIzq = cop-2;
    contDer = cop;
    
    if(criminales[cop-1] == 1)
        ladrones++;
    
    for(int i = 0; i < maxDistancia; i++){
        
        if(contDer == ciudades)
            der = true;
        
        if(contIzq == -1)
            izq = true;
            
        
        if(!der && criminales[contDer] == 1){
            
            if(izq)
                ladrones++;
            else if(criminales[contIzq] == 1){
                ladrones += 2;
            }
        }
        
        if(!izq && criminales[contIzq] == 1){
        
            if(der)
                ladrones++;
        }
        
        contDer++;
        contIzq--;
    }
    
    cout << ladrones;

    return 0;
}
