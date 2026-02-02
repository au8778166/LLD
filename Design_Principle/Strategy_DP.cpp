#include <iostream>
using namespace std;

// Strategy Interface for walk

class WalkableRobot{
    public:
    virtual void walk () = 0;
    virtual ~WalkableRobot() {}

};

// Concrete Strategies for walk

class NormalWalk : public WalkableRobot{
    public:
    void walk(){
        cout<<"Walking normally..."<<endl;
    }
};

class NoWalk : public WalkableRobot{
    public:
    void walk(){
        cout<<"No walk...."<<endl;
    }
};

// strategy for fly.....
class FlyableRobot{
    public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

//Concrete strategy for fly
class NormalFly : public FlyableRobot{
    public:
    void fly() {
        cout<<"Normally Flying..."<<endl;
    }
};

class NoFly : public FlyableRobot{
    public:
    void fly(){
        cout<<"NO Flying"<<endl;
    }
};

//Strategy interface for Talking

class TalkableRobot {
    public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

//Concrete strategy for talk
class NormalTalk : public TalkableRobot{
    public : 
    void talk (){
        cout<<"Talking Normally"<<endl;
    }
};

class NoTalk : public TalkableRobot{
    public : 
    void talk (){
        cout<<"No Talking "<<endl;
    }
};


// Robot Base Class
class Robot{
    protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;
    public:
     Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
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

// Concrete Robot Types
class CompanionRobot : public Robot{
    public:
    CompanionRobot(WalkableRobot* w,TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}
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
// --- Main Function ---
int main() {
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