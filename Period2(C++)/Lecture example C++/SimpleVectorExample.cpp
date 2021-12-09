#include<vector>
#include<iostream>
using namespace std;

int main(){
    vector<float> st1_arr1(5), st1_arr2;
    for(int i = 0; i < 5; i++){
        st1_arr1[i] = (float)i;
        st1_arr2.push_back((float)i);
    }

    cout << "Array 1" << "\tArray 2" <<endl;
    for(int i = 0; i < st1_arr1.size(); i++){
        cout << st1_arr1[i] << "\t" << st1_arr2[i] << endl;
    }
    return 0;
}