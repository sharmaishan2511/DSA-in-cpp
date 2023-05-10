#include<iostream>

using namespace std;

class Test{
private:
    int a;
    static int b;
public:
    Test(){a=10;++b;}
    void disp(){cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;}

};

int Test::b=99;

int main(){
    cout<<"t1 object\n";
    Test t1;                    //once declared it is shared by every class created later
    t1.disp();
    cout<<"t2 object\n";
    Test t2;
    t2.disp();

    return 0;
}
