#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int f, c, holes, querys, aux1, aux2, op, contador;
    string crop[3] = {"Carrots", "Kiwis", "Grapes"};
    bool waste;
    cin >> f >> c >> holes >> querys;
    int wasteland[holes];
    
    for(int i = 0; i < holes; i++){
        cin >> aux1 >> aux2;
        wasteland[i] = ((aux1-1)*c) + aux2-1;
    }
    
    sort(wasteland, wasteland+holes);
    
    for(int i = 0; i < querys; i++){
        cin >> aux1 >> aux2;
        op = ((aux1-1)*c) + aux2-1;
        waste = false;
        
        for(int j = 0; j < holes; j++){
            
            if(op == wasteland[j]){
                waste = true;
                break;
            }
            else if(op < wasteland[j]){
                contador = j;
                break;
            }
            else if(j+1 == holes){
                contador = j+1;
            }
        }
        
        if(waste)
            cout << "Waste” << endl;
        else{
            if(op == 0)
                cout << crop[0] << endl;
            else
                cout << crop[((op-contador)%3)] << endl;
        }
    }

    return 0;
}
