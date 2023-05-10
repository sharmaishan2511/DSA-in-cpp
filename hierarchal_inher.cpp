//hierarchal inheritance
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

class C:public A{
public:
    int c;
    C(){cout<<"Im from C"<<endl;c=30;}
    ~C(){cout<<"Im destructor from C"<<endl;}
};

int main(){
    C c1;
    B b1;
    return 0;
}
