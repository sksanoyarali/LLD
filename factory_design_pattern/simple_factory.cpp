#include<iostream>
using namespace std;
class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger(){}
};
class BasicBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Prepare basic burger "<<endl;
    }
};

class StandardBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Prepare standard burger "<<endl;
    }
};
class PremiumBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Prepare premium  burger "<<endl;
    }
};
class BurgerFactory{
    public:
    Burger* createBurger(string& type){
        if(type=="basic"){
            return new BasicBurger();
        }
        else if(type=="standard"){
            return new StandardBurger();
        }
        else if(type=="premium"){
            return new PremiumBurger();
        }
        else {
             cout << "Invalid burger type! " << endl;
            return nullptr;
        }

    }
};
int main(){
    string type="standard";
    BurgerFactory * factory=new BurgerFactory();

    Burger* b=factory->createBurger(type);
    b->prepare();

}