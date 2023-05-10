#include<iostream>
#include<stack>

using namespace std;

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixtopostfix(string s){
    stack<char> st;
    string res;

    for(int i = 0;i<s.length();i++){
        char c = s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z')){           //if an operand simply add to the string
            res+=c;
        }
        else if(c=='('){                                        //if ( push in the stack
            st.push(c);
        }
        else if(c==')'){                                        //if ) add the top element to result and keep popping till )
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){                                    //pop the last (
                st.pop();
            }
        }else{                                                  //operator
            while(!st.empty() && prec(st.top())>prec(c)){       //while precedence of top operator is greater than current
                res+=st.top();                                  //add it to top and
                st.pop();                                       //then pop it
            }
            st.push(c);                                         //if precedence of c is greater add it to stack
        }
    }

    while(!st.empty()){                                         //simply copy the remaining elements to the stack
            res+=st.top();
            st.pop();
        }

    cout<<res<<endl;
}


int main(){

    string exp= "a+b*(c^d-e)^(f+g*h)-i";
    infixtopostfix(exp);
    return 0;
}
