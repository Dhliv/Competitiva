#include <iostream>
#include <fstream>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}


int main()
{
  ifstream archivo;
  archivo.open("archivo.txt");
  ofstream archivoSalida("test.txt");
  
  int conductores, longitudRuta, takas, pagos;
  int longitudRestante[105], valores[105];
  
  while(cin >> conductores, cin >> longitudRuta, cin >> takas, conductores)
  {
    pagos = 0;
    for(int i=0; i<conductores; i++)
      longitudRestante[i] = longitudRuta;
    
    for(int i = 0; i < conductores; i++)
    {
      int aux;
      cin >> aux;
      longitudRestante[i] -= aux;
    }
    
    for(int i = 0; i < conductores; i++)
    {
      cin >> valores[i];
    }
    
    int contador = conductores-1;
    quickSort(longitudRestante, 0, contador);
    quickSort(valores, 0, contador);
    
    for(int i=contador; i>=0; i--)
    {
        longitudRestante[i] -= valores[i];
    }
    for(int i=0; i<conductores;i++)
    {
      if(longitudRestante[i] < 0)
        pagos += takas*longitudRestante[i];
    }
    
    cout << abs(pagos) << endl;
  }
  
  return 0;
}