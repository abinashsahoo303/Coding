#include<iostream>
#include<list>

using namespace std;

// class IObserver{
//     public:
//     virtual void update(const int val) = 0;
// };

// class IEntity{
//     public:
//     virtual ~IEntity(){ cout << "IEntity Destructor BBYE\n";}
//     virtual void attach(IObserver *obj) = 0;
//     virtual void detach(IObserver *obj) = 0;
//     virtual void notify() = 0;
// };

class observer;

class Subject{
    private:
    std::list<class observer*> obs;
    int value;
    public:
    void attach(observer *ob){
        obs.push_back(ob);
    }
    void detach(observer *ob){
        obs.remove(ob);
    }
    void setval(const int temp){
        value = temp;
        notify(temp);
    }
    void notify(int temp);
};

class observer{
    Subject *item;
    public:
    observer(Subject *temp){
        item = temp;
        item->attach(this);
    }
    void update(int temp){
       cout << "observed new value update on subject : " << temp <<"\n";
    }
};





void Subject::notify(int temp){
    list<observer *>::iterator it = obs.begin();
    while(it != obs.end()){
        (*it)->update(temp);
        ++it;
    }
};


int main(){
    Subject Subo;
    observer ob1(&Subo);
    observer *ob2 = new observer(&Subo); 
    observer ob3(&Subo);

    Subo.setval(6);

    Subo.detach(&ob1);
    Subo.setval(7);

    // return 0;
}