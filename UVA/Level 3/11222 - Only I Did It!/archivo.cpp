#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


// Function to remove duplicate elements 
// This function returns new size of modified 
// array. 
int removeDuplicates(int arr[], int n) 
{ 
    // Return, if array is empty 
    // or contains a single element 
    if (n==0 || n==1) 
        return n; 
  
    int temp[n]; 
  
    // Start traversing elements 
    int j = 0; 
    for (int i=0; i<n-1; i++) 
  
        // If current element is not equal 
        // to next element then store that 
        // current element 
        if (arr[i] != arr[i+1]) 
            temp[j++] = arr[i]; 
  
    // Store the last element as whether 
    // it is unique or repeated, it hasn't 
    // stored previously 
    temp[j++] = arr[n-1]; 
  
    // Modify original array 
    for (int i=0; i<j; i++) 
        arr[i] = temp[i]; 
  
    return j; 
} 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index 
  PREFERIBLEMENTE se manda la posicion '0' como 'low' y 'n-1' (ultima posicion del array) como high */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

int main()
{
  ifstream archivo;
  archivo.open("archivo.txt");
  ofstream archivoSalida("test.txt");
  int cases, resueltosPrimero, resueltosSegundo, resueltosTercero, tamano;
  int primeroRaw[1020], segundoRaw[1020], terceroRaw[1020]; //ARRAYS EN DONDE SE GUARDAN LOS DATOS IGUAL QUE ENTRARON
  int primeroHash[10020], segundoHash[10020], terceroHash[10020]; //EL NOMBRE LO DICE TODO :v
  int totalPrimero, totalSegundo, totalTercero;
  int sinDuplicados1, sinDuplicados2, sinDuplicados3;
  archivo >> cases;
  for(int i = 0; i < cases; i++)
  {
    tamano = 0;
    for(int j = 0; j < 10020; j++)
    {
      primeroHash[j] = 0;
      segundoHash[j] = 0;
      terceroHash[j] = 0;
    }
    
    for(int j = 0; j < 1020; j++)
    {
      primeroRaw[j] = 0;
      segundoRaw[j] = 0;
      terceroRaw[j] = 0;
    }
    
    archivo >> resueltosPrimero;
    totalPrimero = resueltosPrimero;
    for(int j=0; j<resueltosPrimero; j++)
    {
      archivo >> primeroRaw[j];
      if(primeroHash[primeroRaw[j]] == 2)
        totalPrimero--;
      primeroHash[primeroRaw[j]] = 2;
      tamano++;
    }
    
    quickSort(primeroRaw, 0, tamano-1);
    sinDuplicados1 = removeDuplicates(primeroRaw, tamano);
    tamano = 0;
    
    archivo >> resueltosSegundo;
    totalSegundo = resueltosSegundo;
    for(int j=0; j<resueltosSegundo; j++)
    {
      int auxiliar;
      archivo >> auxiliar;
      segundoRaw[j] = auxiliar;
      tamano++;
      if(segundoHash[auxiliar] == 1 or segundoHash[auxiliar] == 2)
        totalSegundo--;
      if(primeroHash[auxiliar] == 2)
      {
        primeroHash[auxiliar] = 1;
        segundoHash[auxiliar] = 1;
        totalSegundo--;
        totalPrimero--;
      }
      else if(primeroHash[auxiliar] == 1 and segundoHash[auxiliar] == 1)
      {
        
      }
      else
      {
        segundoHash[auxiliar] = 2;
      }
    }
    
    quickSort(segundoRaw, 0, tamano-1);
    sinDuplicados2 = removeDuplicates(segundoRaw, tamano);
    tamano = 0;
    
    archivo >> resueltosTercero;
    totalTercero = resueltosTercero;
    for(int j=0; j<resueltosTercero; j++)
    {
      int auxiliar;
      archivo >> auxiliar;
      terceroRaw[j] = auxiliar;
      tamano++;
      if(terceroHash[auxiliar] == 1 or terceroHash[auxiliar] == 2)
        totalTercero--;
      if(primeroHash[auxiliar] == 2)
      {
        primeroHash[auxiliar] = 1;
        terceroHash[auxiliar] = 1;
        totalTercero--;
        totalPrimero--;
      }
      else if(primeroHash[auxiliar] == 1 and terceroHash[auxiliar] == 1)
      {
        primeroHash[auxiliar] = 0;
        terceroHash[auxiliar] = 1;
      }
      else if(primeroHash[auxiliar] == 1)
      {
        primeroHash[auxiliar] = 0;
        terceroHash[auxiliar] = 1;
        totalTercero--;
      }
      else if(terceroHash[auxiliar] == 1)
      {
        terceroHash[auxiliar] = 1;
      }
      else if(terceroHash[auxiliar] == 0)
      {
        terceroHash[auxiliar] = 2;
      }
      
      
      if(segundoHash[auxiliar] == 2)
      {
        segundoHash[auxiliar] = 1;
        terceroHash[auxiliar] = 1;
        totalSegundo--;
        totalTercero--;
      }
      else if(segundoHash[auxiliar] == 1 and terceroHash[auxiliar] == 1)
      {
        segundoHash[auxiliar] = 0;
        terceroHash[auxiliar] = 1;
      }
      else if(segundoHash[auxiliar] == 1)
      {
        segundoHash[auxiliar] = 0;
        terceroHash[auxiliar] = 1;
        totalTercero--;
      }
      else if(terceroHash[auxiliar] == 1)
      {
        terceroHash[auxiliar] = 1;
      }
      else if(terceroHash[auxiliar] == 0)
      {
        terceroHash[auxiliar] = 2;
      }
    }
    
    quickSort(terceroRaw, 0, tamano-1);
    sinDuplicados3 = removeDuplicates(terceroRaw, tamano);
    tamano = 0;
    
    archivoSalida << "Case #" << i+1 << ":" << endl;
    
    if(totalPrimero > totalSegundo and totalPrimero > totalTercero) // El primero es mayor.
    {
      archivoSalida << "1 " << totalPrimero;
        
      for(int k = 0; k<sinDuplicados1; k++)
      {
        if(primeroHash[primeroRaw[k]] == 2)
        {
          archivoSalida << " " << primeroRaw[k];
        }
      }
      
      archivoSalida << endl;
    }
    
    else if(totalSegundo > totalPrimero and totalSegundo > totalTercero) // El segundo es mayor
    {
      archivoSalida << "2 " << totalSegundo;
        
      for(int k = 0; k<sinDuplicados2; k++)
      {
        if(segundoHash[segundoRaw[k]] == 2)
        {
          archivoSalida << " " << segundoRaw[k];
        }
      }
    
      archivoSalida << endl;
    }
    
    else if(totalTercero > totalPrimero and totalTercero > totalSegundo) // El tercero es mayor
    {
      archivoSalida << "3 " << totalTercero;
  
      for(int k = 0; k<sinDuplicados3; k++)
      {
        if(terceroHash[terceroRaw[k]] == 2)
          archivoSalida << " " << terceroRaw[k];
      }
      archivoSalida << endl;
    }
    
    else if(totalPrimero == totalSegundo and totalPrimero == totalTercero) // Todos son iguales.
    {
      archivoSalida << "1 " << totalPrimero;
      
      for(int k = 0; k < sinDuplicados1; k++)
      {
        if(primeroHash[primeroRaw[k]] == 2)
        {
          archivoSalida << " " << primeroRaw[k];
        }
      }
        
      archivoSalida << endl;
      archivoSalida << "2 " << totalSegundo;
        
      for(int k = 0; k<sinDuplicados2; k++)
      {
        if(segundoHash[segundoRaw[k]] == 2)
        {
          archivoSalida << " " << segundoRaw[k];
        }
      }
        
      archivoSalida << endl;
      archivoSalida << "3 " << totalTercero;
        
      for(int k = 0; k<sinDuplicados3; k++)
      {
        if(terceroHash[terceroRaw[k]] == 2)
        {
          archivoSalida << " " << terceroRaw[k];
        }
      }
        
      archivoSalida << endl;
    }
    
    else if(totalPrimero == totalSegundo) // Primero y segundo iguales.
    {
      archivoSalida << "1 " << totalPrimero;
        
      for(int k = 0; k<sinDuplicados1; k++)
      {
        if(primeroHash[primeroRaw[k]] == 2)
        {
          archivoSalida << " " << primeroRaw[k];
        }
      }
        
      archivoSalida << endl;
      archivoSalida << "2 " << totalSegundo;
        
      for(int k = 0; k<sinDuplicados2; k++)
      {
        if(segundoHash[segundoRaw[k]] == 2)
        {
          archivoSalida << " " << segundoRaw[k];
        }
      }
        
      archivoSalida << endl;
    }
    
    else if(totalPrimero == totalTercero) // Primero y Tercero iguales.
    {
      archivoSalida << "1 " << totalPrimero;
        
      for(int k = 0; k<sinDuplicados1; k++)
      {
        if(primeroHash[primeroRaw[k]] == 2)
        {
          archivoSalida << " " << primeroRaw[k];
        }
      }
        
      archivoSalida << endl;
      archivoSalida << "3 " << totalTercero;
        
      for(int k = 0; k<sinDuplicados3; k++)
        {
          if(terceroHash[terceroRaw[k]] == 2)
          {
            archivoSalida << " " << terceroRaw[k];
          }
        }
        
      archivoSalida << endl;
    }
    
    else if(totalSegundo == totalTercero) // Segundo y Tercero iguales.
    {
      archivoSalida << "2 " << totalSegundo;
        
      for(int k = 0; k<sinDuplicados2; k++)
      {
        if(segundoHash[segundoRaw[k]] == 2)
        {
          archivoSalida << " " << segundoRaw[k];
        }
      }
        
      archivoSalida << endl;
      archivoSalida << "3 " << totalTercero;
        
      for(int k = 0; k<sinDuplicados3; k++)
      {
        if(terceroHash[terceroRaw[k]] == 2)
        {
          archivoSalida << " " << terceroRaw[k];
        }
      }
        
      archivoSalida << endl;
    }
  }
  return 0;
}