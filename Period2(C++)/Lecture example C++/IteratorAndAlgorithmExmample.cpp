#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

void main(){
    float array[5] = {3.0, 4.0, 5.0, 2.0, 1.0};
    vector<float> vec(begin(array), end(c_array));

    vector<float> v(5);
    sort(vec.begin(), vec.end());
}