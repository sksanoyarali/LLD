#include <iostream>
using namespace std;

class Food {
public:
    virtual ~Food() {}
};

class VegFood : public Food {};

class NonVegFood : public Food {};
class Animal {
public:
    virtual void eat(Food* food) {
        cout << "Animal eats food\n";
    }

    virtual ~Animal() {}
};
class Lion : public Animal {
public:
    void eat(Food* food) override {
        cout << "Lion eats food\n";
    }
};

int main() {
    Animal* a = new Lion();
    Food* f = new NonVegFood();

    a->eat(f);   // ✅ Lion eats food
    delete a;
}
