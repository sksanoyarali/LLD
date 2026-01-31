#include<iostream>
using namespace std;
class BasePizaa{
    public:
    virtual int cost()=0;
    virtual ~BasePizaa(){}
};
class Margerita:public BasePizaa{
    public:
    int cost() override{
        return 100;
    }
};

class VegDelight:public BasePizaa{
    public:
    int cost() override{
        return 120;
    }
};
class FarmHouse:public BasePizaa{
    public:
    int cost() override{
        return 200;
    }
};

class ToppingDecorator:public BasePizaa{
    public:
    virtual ~ToppingDecorator() {}
};
class ExtraCheese:public ToppingDecorator{
    public:
    BasePizaa * basepizza;
    ExtraCheese(BasePizaa* basepizza){
        this->basepizza=basepizza;
    }
    int cost()override{
        return basepizza->cost()+25;
    }
};
class Mushroom:public ToppingDecorator{
    public:
    BasePizaa * basepizza;
    Mushroom(BasePizaa* basepizza){
        this->basepizza=basepizza;
    }
    int cost()override{
        return basepizza->cost()+10;
    }
};
int main(){
    BasePizaa * pizza=new ExtraCheese(new Mushroom(new Margerita()));
    cout<<pizza->cost();
}