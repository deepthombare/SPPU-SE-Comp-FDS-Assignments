//============================================================================
// Name        : infix.cpp
// Author      : Deep Thombare
// Assignment  : 10
// Description : Hello World in C++, Ansi-style
/*
 * Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions:
 * 1. Operands and operator, both must be single character. 2. Input Postfix expression must be in a desired format.
 * 3. Only '+', '-', '*' and '/ ' operators are expected. */
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;
class Stack{
public:
    int size1;
    int top;
    char *arr;
    char *exp;
    bool isempty(){
        if(top==-1){
           return true;
        }
        return false;
    }
    void push(char val){
        top++;
        arr[top]=val;
    }
    char pop(){
        if(isempty()==true){
            cout<<"Stack underflow"<<endl;
        }
        char val=arr[top];
        top--;
        return val;
    }
    int stacktop(){
        return arr[top];
    }
    int precedence(char ch){
        if(ch=='*'||ch=='/'){
            return 3;
        }
        else if(ch=='+'||ch=='-'){
            return 2;
        }
        else{
            return 0;
        }
    }
    int isOperator(char c){
        if(c=='+'||c=='-'||c=='*'||c=='/'){
            return 1;
        }
        else{
            return 0;
        }
    }
    void infixpostfix(){
        int s = strlen(exp);
        char *p=new char[s];
        int i=0; //Track infix traversal
        int j=0; //Track postfix traversal
        while(i<s){
            if(!isOperator(exp[i])){  //if operand then
                p[j]=exp[i];
                j++;
                i++;
            }
            else{
                if(precedence(exp[i])>precedence(stacktop())){
                    push(exp[i]);
                    i++;
                }
                else{
						p[j]=pop();
						j++;
                }

            }
        }
        while(isempty()==false){
            p[j]=pop();
            j++;
        }
        for(int i=0;i<s;i++){
            cout<<p[i];
        }
        cout<<"\n";
        delete [] p;
    }


};
int main()
{
    Stack s;
    s.size1=100;
    s.top=-1;
    s.arr=new char[s.size1];
    char e='y';
    while(e=='y'){
        cout<<"Enter your expression:-"<<endl;
        cin>>s.exp;
        s.infixpostfix();
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>e;
    }
    return 0;
}
