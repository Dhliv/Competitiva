#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int segs;
    bool yes = false;
    cin >> segs;
    int numeros[segs];
    
    for(int i = 0; i < segs; i++)
        cin >> numeros[i];
    
    sort(numeros, numeros+segs);
    
    for(int i = segs-1; i>=2; i--){
        
        if((numeros[i-1] + numeros[i-2]) > numeros[i]){
            yes = true;
            break;
        }
    }
    
    if(yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
