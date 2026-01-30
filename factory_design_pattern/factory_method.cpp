#include<iostream>
using namespace std;
class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger(){}
};
// normal burgers that prepared by singh burger
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
// wheat burger prepares by king burger
class BasicWheatBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Prepare basic wheat healthy burger"<<endl;
    }
};
class StandardWheatBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Prepare standard wheat healthy burger"<<endl;
    }
};
class PremiumWheatBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Prepare premium wheat healthy burger"<<endl;
    }
};
class BurgerFactory{
    public:
    virtual Burger* createBurger(string & type)=0;
    // virtual ~BurgerFactory(){}
};
class SinghBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicWheatBurger();
        } else if (type == "standard") {
            return new StandardWheatBurger();
        } else if (type == "premium") {
            return new PremiumWheatBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};
int main(){
    string type="standard";
    //singh factory
    BurgerFactory * singhFactory=new SinghBurger();

    Burger * burger=singhFactory->createBurger(type);
    burger->prepare();

    // king factory
    BurgerFactory 
    *kingfactory=new KingBurger();
    Burger* b=kingfactory->createBurger(type);
    b->prepare();

}