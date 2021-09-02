#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    long long int dias, dTotal, ventas = 0, p, c;
    cin >> dias >> dTotal;
    long long int exceso[dias];
    
    for(int i = 0; i < dias; i++){
        cin >> p >> c;
        
        if(p > c){
            exceso[i] = 0;
            ventas += c;
        }
        else{
            
            if(2*p <= c){
                exceso[i] = p;
            }
            else if(2*p >= c and (2*p)/c == 1){
                exceso[i] = abs(c - p);
            }
            else{
                exceso[i] = 0;
            }
            ventas += p;
        }
    }
    
    sort(exceso, exceso+dias);
    
    for(int i = dias-1; i >= dias-dTotal; i--){
        ventas += exceso[i];
    }
    
    cout << ventas << endl;

    return 0;
}
