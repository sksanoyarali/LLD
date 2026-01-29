//strategy interface for payment
#include<iostream>
using namespace std;
class PaymentStrategy{
    public:
    virtual void pay(double amount)=0;
    virtual ~PaymentStrategy() {}
};

// concrete strategy 
class UpiPayment:public PaymentStrategy{
    public:
    void pay(double amount) override{
        cout << "Paying " << amount << " using UPI\n";
    }
};

class CardPayment:public PaymentStrategy{
    public:
    void pay(double amount) override{
        cout << "Paying " << amount << " using Card\n";
    }
};

class PaymentProcessor{
    private:
    PaymentStrategy * strategy;
    public:
    PaymentProcessor(PaymentStrategy* strategy):strategy(strategy){}

     void setStrategy(PaymentStrategy* strategy){
        this->strategy=strategy;
     }
    void pay(double amount) {
        strategy->pay(amount);
    }
};

int main(){
    PaymentProcessor processor(new UpiPayment());
    processor.pay(400);
    
    processor.setStrategy(new CardPayment());
    processor.pay(800);
}