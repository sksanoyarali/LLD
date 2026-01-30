#include<iostream>
using namespace std;
//walkable robot strtegy interface
class WalkableRobot{
    public:
    virtual void walk()=0;
    virtual ~WalkableRobot(){}
};
// concrete strategy for walkable robot
class NormalWalk:public WalkableRobot{
    public:
    void walk() override{
        cout<<"Walking normally"<<endl;
    }
};

class NoWalk:public WalkableRobot{
    public:
    void walk() override{
        cout<<"cannot walk"<<endl;
    }
};
//flyable
class FlyableRobot{
    public:
    virtual void fly()=0;
    virtual ~FlyableRobot(){}
};
 // concrete strategy for Flyable robot
class NormalFly:public FlyableRobot{
    public:
    void fly() override{
        cout<<"flying normally"<<endl;
    }
};
class NoFly:public FlyableRobot{
    public:
    void fly() override{
        cout<<"cannot fly"<<endl;
    }
};
// talkable interface 
class TalkableRobot{
    public:
    virtual void talk()=0;
    virtual ~TalkableRobot(){}
};

// concrete strategy for talkable
class NormalTalk:public TalkableRobot{
    public:
    void talk() override{
        cout<<"talking normally"<<endl;
    }
};
class NoTalk:public TalkableRobot{
    public:
    void talk() override{
        cout<<"cannot talk"<<endl;
    }
};
class Robot{
    protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;
    public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
    : walkBehavior(w),
      talkBehavior(t),
      flyBehavior(f){

      }

    void walk() { 
        walkBehavior->walk(); 
    }
    void talk() { 
        talkBehavior->talk(); 
    }
    void fly() { 
        flyBehavior->fly(); 
    }

    virtual void projection() = 0; // Abstract method for subclasses
};

class CompanionRobot:public Robot{
    public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f):Robot(w,t,f){}

     void projection() override {
        cout << "Displaying friendly companion features..." << endl;
    }
};
class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

int main(){
     Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout << "--------------------" << endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}