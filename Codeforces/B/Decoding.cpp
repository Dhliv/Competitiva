#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
 
using namespace std;
 
int main()
{
    string palabra, decoded = "";
    int lenght, contador = 0;
    
    cin >> lenght;
    cin >> palabra;
    
    for(int i = 0; i < lenght; i++){
        decoded += "a";
    }
    
    for(int i = lenght; i > 0; i--){
        
        if(i%2 == 1){
            decoded[(i/2) + contador] = palabra[contador];
            contador++;
        }
        else{
            decoded[(i/2) - 1] = palabra[contador];
            contador++;
        }
    }
    
    cout << decoded;
 
    return 0;
}