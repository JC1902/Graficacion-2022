#include <iostream>

using namespace std;

#include <iomanip>

using std::setw;

double getAverage(int arr[], int size) {
  int i, sum = 0;
  double avg;

   for (i = 0; i < size; ++i) {
      sum += arr[i];
   }
   avg = double(sum) / size;

   return avg;
}

int * getRandom( ) {

   static int  r[10];//arreglo con 10 elementos

   //se crean números aleatorios
   srand( (unsigned)time( NULL ) );

   //se le dan valores aleatorios al arreglo
   for (int i = 0; i < 10; ++i) {
      r[i] = rand();
      cout << r[i] << endl;
   }

   return r;
}

int main()
{
    srand(time(NULL));//Los números cambian según el momento en el que se ejecuta el programa
    cout << "----------Ejemplo 1----------" << endl;
    int n[ 10 ] = {3,4,5,12,54,63,32,67,91,10}; // arreglo de 10 números enteros

       cout << "Element" << setw( 13 ) << "Value" << endl;//setw da un formato de anchura

       // se muestran los valores del arreglo
       for ( int j = 0; j < 10; j++ ) {
          cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
       }

       //el mismo arreglo cambiando los valores del ancho
       cout << setw(13) << "Element" << setw( 19 ) << "Value" << endl;
       for ( int j = 0; j < 10; j++ ) {
          cout << setw( 13 )<< j << setw( 19 ) << n[ j ] << endl;
       }

       for(int i = 0; i < 10; i++){
           if(n[i] > 30)
               cout << "Este numero es mayor a 30: " << n[i] << endl;
           else
               cout << "Este numero es menor a 30: " << n[i] << endl;
       }

       //                   Siguiente ejemplo                       //
       cout << "----------Ejemplo 2----------" << endl;
       // arreglo de 5 filas y 2 columnas
       int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};

          // mostrar los valores del arreglo
          for ( int i = 0; i < 5; i++ ){
             for ( int j = 0; j < 2; j++ ) {
                cout << "a[" << i << "][" << j << "]: ";
                cout << a[i][j]<< endl;
             }
          }

          cout<<"Arreglo si se suma de 2 en 2 la i: "<<endl;
          for ( int i = 0; i < 5; i = i+2 ){
             for ( int j = 0; j < 2; j++ ) {
                cout << "a[" << i << "][" << j << "]: ";
                cout << a[i][j]<< endl;
             }
          }

         //                   Siguiente ejemplo                       //
          cout << "----------Ejemplo 3----------" << endl;
          // arreglo con 5 elementos
             double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
             double *p;

             p = balance;

             //mostrar los valores del arreglo
             cout << "Valores del arreglo usando punteros " << endl;

             for ( int i = 0; i < 5; i++ ) {
                cout << "*(p + " << i << ") : ";
                cout << *(p + i) << endl;
             }
             cout << "Valores del arreglo usando balance como direccion " << endl;

             for ( int i = 0; i < 5; i++ ) {
                cout << "*(balance + " << i << ") : ";
                cout << *(balance + i) << endl;
             }

             cout << "Valores al multiplicar *(p + i) por dos: " << endl;
             for(int i = 0; i < 5; i++)
                cout  << "*(p + " << i << ") x 2 : " << *(p + i) * 2 << endl;

         //                   Siguiente ejemplo                       //
             cout << "----------Ejemplo 4----------" << endl;
             // arreglo de enteros con 5 elementos.
                int bala[5] = {1000, 2, 3, 17, 50};

                int bala2[5] = {rand()%45+12,rand()%90+12,
                                  rand()%47+4,rand()%30+5,rand()%20+10};//los números del arreglo son aleatorios
                double avg, avg2;

                // pasar un puntero al arreglo como argumento.
                avg = getAverage( bala, 5 ) ;
                avg2 = getAverage(bala2, 5);//se obtiene el promedio con el arreglo de números aleatorios

                // mostrar el valor que se regresa
                cout << "El valor promedio es: " << avg << endl;
                cout << "El valor promedio usando numeros aleatorios es: " << avg2 << endl;

          //                   Siguiente ejemplo                       //
                cout << "----------Ejemplo 5----------" << endl;
                // puntero a un int.
                   int *q;
                   int mayor, menor;
                   q = getRandom();

                   for ( int i = 0; i < 10; i++ ) {
                      cout << "*(q + " << i << ") : ";
                      cout << *(q + i) << endl;
                   }

                   for(int j = 0; j < 10; j++){
                       if(mayor < *(q+j))
                           mayor = *(q+j);
                   }

                   menor = mayor;

                   for(int j = 0; j < 10; j++){
                       if(menor > *(q+j))
                           menor = *(q+j);
                   }

                   cout << "El valor mayor es: " << mayor << endl;
                   cout << "El valor menor es: " << menor << endl;

    return 0;
}
