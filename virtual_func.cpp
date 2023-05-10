#include<iostream>

using namespace std;

class Base{
public:
    virtual void fun1()=0; //pure virtual function
    virtual void disp(){cout<<"im from base class"<<endl;}
    virtual void fun(){cout<<"im a function from base class"<<endl;}
};

class Derived:public Base{
public:
    void disp(){cout<<"im from derived class"<<endl;}
    void fun(){cout<<"im a function from derived class"<<endl;}
    virtual void fun1(){cout<<"implemented pure virtual function"<<endl;}
};

int main(){
    Base *ptr;
    Derived d1;
    ptr = &d1;
    ptr->disp();
    ptr->fun();
    ptr->fun1();

    ptr->Base::disp();
    ptr->Base::fun();
    return 0;
}
