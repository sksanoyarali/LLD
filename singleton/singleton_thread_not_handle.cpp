#include<iostream>
using namespace std;
// this is not safe for multithreading
// because if two t1 and t2 enter at the same time
// both will create object violate signle singleton

// some points
// Constructors CANNOT be static in C++
// Constructors initialize objects

// Static belongs to class, not object

// No this pointer in static context
class Singleton{
    private:
    static Singleton * instance;
    Singleton(){
        cout<<"default constructor,object created"<<endl;
    }
    public:
    static Singleton* getInstance(){
        if(instance==nullptr){
            instance=new Singleton();
        }
        return instance;
    }
};
Singleton* Singleton::instance=nullptr;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}