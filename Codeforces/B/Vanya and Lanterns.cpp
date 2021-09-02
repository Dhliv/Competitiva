#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int linternas, distancia, aux;
    long double mayor = 0.0;
    
    cin >> linternas;
    cin >> distancia;
    
    long long int pLinternas[linternas];
    long double minD[linternas+2];
    
    for(int i = 0; i < linternas; i++){
        
        cin >> pLinternas[i];
        minD[i] = 0.0;
    }
    
    minD[linternas] = 0.0;
    minD[linternas+1] = 0.0;
    
    sort(pLinternas, linternas+pLinternas);
    
    minD[0] = pLinternas[0];
    
    if(minD[0] > mayor)
        mayor = minD[0];
    
    minD[linternas+1] = (distancia - pLinternas[linternas-1]);
    
    if(minD[linternas+1] > mayor)
        mayor = minD[linternas+1];
    
    for(int i = 0; i < linternas; i++){
        
        if(i == linternas-1){}
        else {
            minD[i+1] = (pLinternas[i+1] - pLinternas[i])/(2.0);
            
            if(minD[i+1] > mayor)
                mayor = minD[i+1];
        }
    }
    
    cout.precision(19);
    cout << mayor;
 
    return 0;
}