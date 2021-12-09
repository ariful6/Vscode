#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <iomanip>
using namespace std;

int main(){
    vector<double> vec;                         //varibales
    double num = 0;

    cout << "Enter your numbers and to stop enter negative number." << endl;
    cout << "Number: ";
    cin >> num;
    while(num>=0){
        vec.push_back(num);
        cout << "Enter your numbers and to stop enter negative number." << endl;
        cout << "Number: " ;
        cin >> num;
    }
    sort(vec.begin(), vec.end());                                               //sorting the vector    
    cout << "You entered: \n";
    for (int i = 0; i < vec.size(); i++){
        cout << fixed << setprecision(3) << vec[i] << "\n";                     //printing the number upto 3 decimal
    }

    return 0;
}

