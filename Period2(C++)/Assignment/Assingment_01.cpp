#include <iostream>
#include <string>
#include <cstdlib>
using namespace::std;

int mean(int *array, int n);                         //function declaration

int main(){
    cout << "Enter the number: ";                  //ask user for how many number
    int number = 0; int *array;                     //declaring variables
    cin >> number;
    
    array = new int[number] ;                       //Allocates memory space to store the number
    
    for (int i = 0; i < number; i++) {              //filling the array with random number 0-99
        array[i] = rand() % 100;
    }

    cout << "Array: ";
    for (int i = 0; i < number; i++) {
       cout << array[i] <<" ";
    }

    cout << endl;
    cout << "Mean: " << mean(array, number)<< endl;         //Calling the funtion mean
    delete array;
}
int mean(int *array, int n){
   
    int sum = 0; double mean = 0;                            //declaring and initializing variable
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    mean = sum / n;
    return mean;
}
