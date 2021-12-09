#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
using namespace std;

class RandGen{                                                    //funtion object
    public:
        RandGen(int x, int y): numbers() {
            srand((unsigned int)time(NULL));
            num1 = x;
            num2 = y;
        }
        int operator()();
    private:
        int num1, num2;
        vector<int> numbers;
};

int main (){
    int x = 1;                                              //varibales declaration

    while (x == 1){
        vector<int> lotto(7);
        vector<int> vikingLotto(6);
        vector<int> euroJackpot(5);
        vector<int> twoSets;
        vector<int> threeSets;
        
        RandGen randGen_1(1, 40);                                                //Generating random numbers for Lotto
        generate (lotto.begin(), lotto.end(), randGen_1);
        cout << "Lotto: ";
        for (auto n : lotto)
            cout << n << " ";
        cout << endl;
        
        RandGen randGen_2(1, 48);                                                 //Generating random numbers for Viking lotto
        generate(vikingLotto.begin(), vikingLotto.end(), randGen_2);
        cout << "Viking Lotto: ";
        for (auto n: vikingLotto)
            cout << n << " ";
        cout << endl;
        
                                                                        //Finding macthing numbers between lotto and vaiking lotto
        int m = 1;                                                      //for indexing
        set_intersection(lotto.begin(),lotto.end(),
                         vikingLotto.begin(),vikingLotto.end(),back_inserter(twoSets));
                                                                                    //printing the macthing numbers for two sets
        cout <<"Matching numbers:"<<endl;
        auto print = [&m](const int& n){cout << "#"<< m <<": "<< n<<endl;
            m++;};                                                               //incrementing the index inside lamda
        for_each(twoSets.begin(), twoSets.end(), print);
        
        RandGen randGen_3(1, 50);                                                //Generating random numbers for Eurojackpot
        generate(euroJackpot.begin(), euroJackpot.end(), randGen_3);
        cout << "Eurojackpot: ";
        for (auto n: euroJackpot)
            cout << n << " ";
        cout << endl;
        
                                                                        //Finding macthing numbers between lotto and vaiking lotto
        set_intersection(twoSets.begin(), twoSets.end(),                        //comparing 2 set match vs eurojackpot
                         euroJackpot.begin(),euroJackpot.end(),
                         back_inserter(threeSets));
        
                                                                                //Printing the matching number for 3 sets
        m = 1;                                                                  //reinitialize the value so index start from 1 again
        cout <<"Matching numbers in three sets:"<<endl;
        for_each(threeSets.begin(), threeSets.end(), print);
        cout << endl;
        
        cout <<"To continue press 1 or 0 to exit"<<endl;
        cin >> x;
    }

    return 0;
}

int RandGen::operator()(){
    int number;
    do {
        number = (rand() % (num2 - num1 + 1)) + num1 ;
    }
    while(find(numbers.begin(), numbers.end(), number) != numbers.end());
        numbers.push_back(number);
        return number;
}
