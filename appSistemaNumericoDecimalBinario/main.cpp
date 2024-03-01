#include <iostream>
#include <cmath>
#include<cstring>

using namespace std;

int MAX = 32;

int * decBinario(int num){
    int i = 0;
    int *result = new int [MAX];
    for( i = 0; i<MAX; i++)
        result[i] = 0;
    i=0;
    while(num > 0){
        result[i] = num%2;
        num /= 2;
        i++;
    }
    return result;
}

int main()
{
    char opc;
    int *bin = new int [32];
    int num;
    char convertirA;
    //string numBin;
    char numBin[32];
    do{
        cout<<"1.-Convertir a binario o 2.- Convertir a decimal (1/2): "<<endl;
        cin>>convertirA;
        if(convertirA == '1'){
            cout<<"Numero decimal: ";
            cin>>num;
            bin = decBinario(num);

            for(int i = MAX - 1; i>=0; i--){
            cout<<bin[i];
            }
        }
        else{
            cout<<"Numero binario: ";
            cin>>numBin;

            int exp = 0;
            /*for(int i=numBin.length()-1; i >= 0; i--){
                if(numBin[i] == '1')
                    num += pow(2,exp);
                else
                    num += 0;

                exp++;
            }
            cout<<num<<endl; Convertir a decimal usando String*/

            //Convertir a decimal usando arreglo de caracteres
            for(int i=MAX-1; i >=0; i--){
                if(numBin[i] == '1')
                    num += pow(2,exp);
                else
                    num += 0;

                exp++;
            }
            cout<<num<<endl;
        }
        cout<<endl;
        cout<<"Otro (s/n): ";
        cin>>opc;
        opc = tolower(opc);


    }while(opc == 's');

    delete []bin;
    return 0;
}
