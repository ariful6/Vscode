#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    //declaring the variables
    string str1; int longest = 0;
    vector <string> str1_arr;
    int n = 0;                          
   //ask user to input strings
    cout << "Enter a string: ";
    cin >> str1;
    while (str1 != "stop") {
        str1_arr.push_back(str1);
        cout << "Enter a string: ";
        cin >>str1;
        n++;                                                    //counting for string number entered
    }
    cout <<"String entered: ";
    for (int i = 0; i < str1_arr.size(); i++) {                 //displaying the string array
        cout << str1_arr[i] <<" ";
        if(str1_arr[i].size()>str1_arr[longest].size())         //sorting the longest string
            longest = i; 
    }
    cout <<"\nNumer of string Entered: " << n <<endl;
    cout <<"Longest string: " <<str1_arr[longest] <<"  Length: "<<str1_arr[longest].size() <<endl;
    cout <<"Size of String Array: " <<str1_arr.size()<<endl;
    cout <<"Capacity of String Array: " <<str1_arr.capacity()<<endl;

}
