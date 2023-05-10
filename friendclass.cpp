#include<iostream>

using namespace std;
class B;
class A{
    int a;
    public:
        A(){a=10;}
        void print_data(){cout<<"the value of a = "<<a<<endl;}
        friend class B;     //due to this class B can access the elements of A class
};

class B{
    int b;
    public:
        B(){b=20;}
        void print_data(A obj){cout<<"the value of b = "<<b<<" From class A we have = "<<obj.a<<endl;}
};

int main(){
    A t1;
    t1.print_data();
    B t2;
    t2.print_data(t1);
    return 0;
}
