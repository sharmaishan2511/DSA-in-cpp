#include<iostream>
#include<stack>

using namespace std;

void evalpostfix(string s){
    stack<char> st;
    int res;

    for(int i = 0;i<s.length();i++){
        char c=s[i];

        if(isdigit(c)){
            st.push(c);
        }else{
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();

            int n1=a-'0';
            int n2=b-'0';

            int m;
            char d;

            switch(c){
            case '+':
                m = n1+n2;
                d = '0'+m;
                st.push(d);
                break;
            case '-':
                m = n2-n1;
                d = '0'+m;
                st.push(d);
                break;
            case '*':
                m = n1*n2;
                d = '0'+m;
                st.push(d);
                break;
            case '/':
                m= n1/n2;
                d = '0'+m;
                st.push(d);
                break;
            }
        }

    }
    cout<<st.top()-'0';
}


int main(){
    string exp = "231*+9-";
    evalpostfix(exp);

    return 0;
}
