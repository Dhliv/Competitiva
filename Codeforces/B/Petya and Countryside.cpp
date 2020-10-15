#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
 
using namespace std;
 
int main()
{
    int zonas, maximo = 0;
    
    cin >> zonas;
    int mounds[zonas], maximos[zonas];
    
    for(int i = 0; i < zonas; i++){
        cin >> mounds[i];
        maximos[i] = 0;
    }
    
    for(int i = 0; i < zonas; i++){
        
        int aux = 1;
        for(int j = i; j < zonas-1; j++){
            
            if(mounds[j] >= mounds[j+1]){
                aux++;
            }
            else
                break;
        }
        
        for(int j = i; j > 0; j--){
            
            if(mounds[j] >= mounds[j-1]){
                aux++;
            }
            else
                break;
        }
        
        if(aux > maximo)
            maximo = aux;
    }
    
    cout << maximo;
 
    return 0;
}