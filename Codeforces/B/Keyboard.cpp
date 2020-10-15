#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{

  long long INF = 10000000000000000;
  long long inf = 10000000000000000;
  int radio, filas, teclas, contador = 0, textL, dist, letricas = 0;
  int eses[900][2];
  int hash[255];

  cin >> filas >> teclas >> radio;
  string aux, texto;
  char letra, teclado[filas][teclas];

  for(int i = 0; i < 255; i++){
    hash[i] = 0;
  }

  for(int i = 0; i < filas; i++){
    cin >> aux;
    for(int j = 0; j < teclas; j++){
      hash[aux[j]] = 1;
      if(aux[j] == 'S'){
        eses[contador][0] = i;
        eses[contador][1] = j;
        contador++;
      }
      teclado[i][j] = aux[j];
    }
  }

  cin >> textL >> texto;


  for(int i = 0; i < 26; i++){
    letra = 97+i;

    if(hash[letra] == 1){
      
      for(int i = 0; i < filas; i++){
        for(int j = 0; j < teclas; j++){
          if(letra == teclado[i][j]){

            for(int k = 0; k < contador; k++){
              dist = pow((i - eses[k][0]), 2) + pow((j - eses[k][1]) , 2);
              if(dist < inf)
                inf = dist;
            }
          }
        }

        if(i+1 == filas){
            
          hash[letra] = inf;
          inf = INF;
        }
      }

    }
  }

  for(int i = 0; i < textL; i++){

    if(96 < texto[i] && texto[i] < 123){
      
      if(hash[texto[i]] == 0){
        letricas = -1;
        break;
      }
    }
    else{
        letra = texto[i] + 32;

        //cout << letra << " " << hash[letra] << endl;
        if(contador == 0){
          letricas = -1;
          break;
        }

        if(hash[letra] == 0){
          letricas = -1;
          break;
        }

        if(hash[letra] > pow(radio, 2))
          letricas++;
    }
  }

  cout << letricas;


  //map<long long int, long long int> leMape;
  //leMape.insert(pair <long long int, long long int>(op, i));

 //g++ -std=c++11 *.cpp -o Main
  return 0;
}
