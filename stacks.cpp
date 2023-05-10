#include<iostream>
#include<stack>

using namespace std;

int main(){

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();

    cout<<"top element is : "<< s.top()<<endl;
    cout<<"is empty check 1 is yes 0 is no : "<<s.empty() ;

    return 0;
}
