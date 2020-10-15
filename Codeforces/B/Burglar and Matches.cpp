#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    int fosforos = 0, cajas, contenedores, max = 0, pos, contador;
    cin >> cajas >> contenedores;
    
    int warehouse[contenedores][2];
    
    for(int i = 0; i < contenedores; i++){
        cin >> warehouse[i][0];
        cin >> warehouse[i][1];
        
        if(warehouse[i][1] > max){
            max = warehouse[i][1];
            pos = i;
        }
    }
    
    while(cajas > 0){
        
        if(max > 0){
            
            if(warehouse[pos][0] < cajas){
                fosforos += warehouse[pos][1]*warehouse[pos][0];
                cajas -= warehouse[pos][0];
                warehouse[pos][1] = 0;
                max = 0;
            }
            else{
                fosforos += warehouse[pos][1]*cajas;
                cajas = 0;
                max = 0;
            }
        }
        else{
            contador = 0;
            for(int i = 0; i < contenedores; i++){
                if(warehouse[i][1] > max){
                    max = warehouse[i][1];
                    pos = i;
                }
                
                if(warehouse[i][1] == 0)
                    contador++;
            }
            
            if(contador == contenedores)
                cajas = 0;
        }
    }
    
    cout << fosforos;

    return 0;
}
