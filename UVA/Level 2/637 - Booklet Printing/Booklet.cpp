#include <iostream>
using namespace std;

int main()
{
 int paginas, hojas, sobrantes;
 
 while(cin >> paginas, paginas != 0)
 {
   hojas = paginas/4;
   sobrantes = paginas % 4;
   int inicial = 0;
   int final = paginas;
   
   cout << "Printing order for " << paginas << " pages:" << endl;
   
   if(paginas == 1)
   {
     cout << "Sheet " << 1 << ", front: Blank, " << 1 << endl;
   }
   
   else if(sobrantes == 0)
   {
     for(int i = 0; i < hojas; i++)
     {
       cout << "Sheet " << i+1 << ", front: " << final << ", " << inicial+1 << endl;
       cout << "Sheet " << i+1 << ", back : " << inicial+2 << ", " << final-1 << endl;
       inicial += 2;
       final += -2;
     }
   }
   
   else if(sobrantes == 1)
   {
     cout << "Sheet " << 1 << ", front: Blank, " << 1 << endl;
     cout << "Sheet " << 1 << ", back : " << 2 << ", Blank" << endl;
     cout << "Sheet " << 2 << ", front: Blank, 3" << endl;
     cout << "Sheet " << 2 << ", back : 4, " << final << endl;
     final += -1;
     inicial += 4;
     
     for(int i = 0; i < hojas-1; i++)
     {
       cout << "Sheet " << i+3 << ", front: " << final << ", " << inicial+1 << endl;
       cout << "Sheet " << i+3 << ", back : " << inicial+2 << ", " << final-1 << endl;
       inicial += 2;
       final += -2;
     }
   }
   
   else if(sobrantes == 2)
   {
     cout << "Sheet " << 1 << ", front: Blank, " << 1 << endl;
     cout << "Sheet " << 1 << ", back : " << 2 << ", Blank" << endl;
     inicial += 2;
     
     for(int i = 0; i < hojas; i++)
     {
       cout << "Sheet " << i+2 << ", front: " << final << ", " << inicial+1 << endl;
       cout << "Sheet " << i+2 << ", back : " << inicial+2 << ", " << final-1 << endl;
       inicial += 2;
       final += -2;
     }
   }
   
   else if(sobrantes == 3)
   {
     cout << "Sheet " << 1 << ", front: Blank, " << 1 << endl;
     cout << "Sheet " << 1 << ", back : " << 2 << ", " << final << endl;
     inicial += 2;
     final += -1;
     
     for(int i = 0; i < hojas; i++)
     {
       cout << "Sheet " << i+2 << ", front: " << final << ", " << inicial+1 << endl;
       cout << "Sheet " << i+2 << ", back : " << inicial+2 << ", " << final-1 << endl;
       inicial += 2;
       final += -2;
     }
   }

 }
  
  return 0;
}