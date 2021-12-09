#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


class Person {
public:
    Person(const char* name = "nobody");
	virtual ~Person() = default;
	virtual void identity() const;
    virtual void interrogate();
private:
	std::string name1;
};

//spy class derived from class Person
class Spy: public Person {
public:
    Spy(const char* name, const char* alias, const int resistance ): name2{name}, alias1{alias},resistance1{resistance}{};      //constractor takes 3 parameters and initializing parameters
    virtual ~Spy() = default;
    void set_identity(const char *alias);
    virtual void identity() const;
    virtual void interrogate(){resistance1--;};         //decreament everytime interrogate() called
private:
    //variable declaration
    std::string name2;
    std::string alias1;
    int resistance1;
    
};


int main(int argc, char** argv) {

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);

	std::cout << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy2.interrogate();
		spy2.identity();
	}

	return 0;
}
//implementing functions
Person::Person(const char* name){
    name1 = name;
}

void Person::identity()const{
    std::cout <<"My name is: "<<name1<<std::endl;
}
void Person::interrogate(){

}

void Spy::identity()const{
    if (resistance1>0) {                    //condition if resistance is greater than 0
        std::cout <<"My name is: "<<alias1<<std::endl;
    }
    else if (resistance1 < 1){
		std::cout <<"My name is: "<<name2<<std::endl;
        std::cout <<"My alias is: "<< alias1<<std::endl;
        }
}

void Spy::set_identity(const char *alias){
    alias1 = alias;
}
