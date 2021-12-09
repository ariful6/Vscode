#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <iomanip>
using namespace std;

void backward(vector<string> &arr);                                 //Declaring the funtion

int main(){
    string str1; vector<string> str_arr;                            //declaring the variables
    cout << "Enter a string and to stop, type 'stop' "<< endl;      //asking user to enter string
    cout << "String : " ;
    cin >> str1;
    while (str1 != "stop"){                                         //keep asking until 'stop' is typed
        str_arr.push_back(str1);                                    //stores all the strings in a vector of strings
        cout << "Enter a string and to stop, type 'stop' "<< endl;      //asking user to enter string
        cout << "String : " ;
        cin >> str1;
    }
        cout << "You entered: ";                                    // displaying the string typed
        for (int i = 0; i < str_arr.size(); i++){
            cout << str_arr[i] << " ";
        }
    cout << endl;

    backward(str_arr);                                              //calling fucntion backward
    cout << "Backward: ";
    for (int i = 0; i < str_arr.size(); i++){                       //displaying strings in backward decending order
        cout << str_arr[i] <<" ";
    }    

    cout << endl;
    return 0;
}
void backward(vector<string> &arr){
    vector<string> array;                                          //variable
    array = arr;
    reverse(array.begin(), array.end());                           //reversing the vector string array
    sort(array.begin(), array.end(), greater<string>());            //sorting in decending order
    arr = array;
}  