#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    long long int stones, costo, querys, question, izq, der;
    cin >> stones;
    long long int piedras[stones], sumaPiedras[stones], piedrasOrden[stones], sumaPiedrasOrden[stones];
    
    for(int i = 0; i < stones; i++){
        cin >> piedras[i];
        piedrasOrden[i] = piedras[i];
        
        if(i == 0){
            sumaPiedras[i] = piedras[i];
        }
        else{
            sumaPiedras[i] = piedras[i] + sumaPiedras[i-1];
        }
    }
    
    sort(piedrasOrden, piedrasOrden + stones);
    
    for(int i = 0; i < stones; i++){
        if(i == 0){
            sumaPiedrasOrden[i] = piedrasOrden[i];
        }
        else{
            sumaPiedrasOrden[i] = piedrasOrden[i] + sumaPiedrasOrden[i-1];
        }
    }
    
    cin >> querys;
    
    for(int i = 0; i < querys; i++){
        
        cin >> question >> izq >> der;
        
        if(question == 1){
            if(izq-2 < 0){
                costo = sumaPiedras[der-1];
            }
            else{
                costo = sumaPiedras[der-1] - sumaPiedras[izq-2];
            }
        }
        else{
            if(izq-2 < 0){
                costo = sumaPiedrasOrden[der-1];
            }
            else{
                costo = sumaPiedrasOrden[der-1] - sumaPiedrasOrden[izq-2];
            }
        }
        
        cout << costo << endl;
    }

    return 0;
}
