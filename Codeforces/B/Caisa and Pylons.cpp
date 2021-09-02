#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    int energia = 0, dinero = 0, pylons, gasto;
    cin >> pylons;
    int torres[pylons+1];
    torres[0] = 0;
    
    for(int i = 1; i <= pylons; i++){
        cin >> torres[i];
    }
    
    for(int i = 0; i < pylons; i++){
        
        if(torres[i] >= torres[i+1]){
            energia += torres[i] - torres[i+1];
        }
        else{
            
            gasto = torres[i+1] - torres[i];
            if(energia >= gasto)
            {
                energia -= gasto;
            }
            
            else if(energia > 0){
                dinero += gasto - energia;
                energia = 0;
            }
            else{
                dinero += gasto;
            }
        }
    }
    
    cout << dinero;

    return 0;
}
