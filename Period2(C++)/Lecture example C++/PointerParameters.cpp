#include <iostream>
using namespace std;

//prototype of swap
void swap( int *a, int *b);

//applicaiton
int main(){
    
    int number1 = 1, number2 = 2;

    swap(&number1, &number2);

    cout << number1 << " " << number2 << endl;

    return 0;
 
}

//implementation of swap
void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}