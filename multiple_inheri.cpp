//multiple inheritance
#include<iostream>
using namespace std;
class Base_1{
    protected:
        Base_1(){
            cout<<"im from base 1"<<endl;
            func();
        }
        void disp(){cout<<"im also from base 1"<<endl;}
        void func(){cout<<"im a base 1 function"<<endl;}

    public:

};

class Base_2{
    protected:
        Base_2(){
            cout<<"im from base 2"<<endl;
        }
        void disp(){cout<<"im also from base 2"<<endl;}

};

class Derived: public Base_2,public Base_1{
        public:
            Derived(){cout<<"im from derived"<<endl;}
            void disp(){
                cout<<"im also from derived"<<endl;
                Base_2::disp();
            }
    void disp(int x){
        cout<<"im from derived:"<<x<<endl;
    }
};

int main(){
    Derived d1;
    d1.disp();

    return 0;
}
