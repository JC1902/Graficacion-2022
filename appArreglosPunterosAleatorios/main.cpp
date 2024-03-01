#include <iostream>
#include <ctime>

using namespace std;

// function to generate and retrun random numbers.
int * getRandom( ) {

   static int  r[10];

   // set the seed
   srand( (unsigned)time( NULL ) );

   for (int i = 0; i < 10; ++i) {
      r[i] = rand() % 90 + 10;
      cout << r[i] << endl;
   }
   cout << "\a\a\aDireccion de r: "<<r<<endl;
   return r;
}

// main function to call above defined function.
int main () {
   // a pointer to an int.
   int *p;

  // cout<<"Valor de la direccion de p: "<<p<<endl;

   p = getRandom();

   cout<<"\a Valor de la direccion de p despues de random: "<<p<<endl;

   for ( int i = 0; i < 10; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;

      cout << "p[ " << i << "] : ";
      cout << p[i] << endl;
   }
    return 0;
}
