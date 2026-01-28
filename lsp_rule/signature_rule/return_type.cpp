#include <iostream>

using namespace std;

// Return Type Rule : 
// Subtype overriden method return type should be either identical 
// or narrower then the parent method's return type.
// This is also called as return type covariance.
// C++ enforces this by covariance.

//whats not allowed
    //   if Animal class have a parent class like living child class cannot
    // return object of living class because Animal* 
    // cant hold living*

class Animal{
    //some common animal methods
};
class Dog:public Animal{
    //some speciic dog method
};
class Parent{
    public:
    virtual Animal* getAnimal(){
         cout << "Parent : Returning Animal instance" << endl;
        return new Animal();
    }
};

class Child:public Parent{
    public:
    Animal* getAnimal() override{
         cout << "Child : Returning Dog instance" << endl;
        return new Animal();
    }
};

class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }
    void takeAnimal() {
        p->getAnimal();
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(child);
    // Client * client = new Client(parent);
    client->takeAnimal();

    return 0;
}
