//multilevel inheritance
#include<iostream>

using namespace std;

class A{
public:
    int a;
    A(){cout<<"Im from A"<<endl;a=10;}
    ~A(){cout<<"Im destructor from A"<<endl;}

};

class B:public A{
public:
    int b;
    B(){cout<<"Im from B"<<endl;b=20;}
    ~B(){cout<<"Im destructor from B"<<endl;}

};

class C:public B{
public:
    int c;
    C(){cout<<"Im from C"<<endl;c=30;}
    ~C(){cout<<"Im destructor from C"<<endl;}
};

int main(){
    /*cout<<"a1 object is created"<<endl;
    A a1;
    cout<<"b1 object is created"<<endl;
    B b1;
    cout<<"c1 object is created"<<endl;
    C c1;*/
    C c1;
    return 0;
}
