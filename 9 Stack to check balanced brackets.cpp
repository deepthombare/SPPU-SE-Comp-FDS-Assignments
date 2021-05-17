// Name        : Check balanced equation .cpp
// Author      : Deep Thombare
// Assignment  : 9
/*In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[].
 *  Write C++ program using stack to check whether given expression is well parenthesized or not
 * */
#include <iostream>
using namespace std;

class Stack{
private:
	int top;
	int len;
	char *st;
	string exp;
public:
	Stack(){
		cout<<"Enter expression: ";
		cin>>exp;
		len=exp.size();
		st=new char[len];
		top=-1;
	}

	void push(char ch){
		st[++top]=ch;
	}

	char pop(){
		return st[top--];
	}

	void checkExpression(){
		bool flag=true;
		for(int i=0;i<len;i++){
			if(top==-1 && (exp[i]=='}' || exp[i]==']' || exp[i]==')')){
				flag=false;
				break;
			}
			if(exp[i]=='{' || exp[i]=='[' || exp[i]=='('){
				push(exp[i]);
			}
			else if(exp[i]=='}' || exp[i]==']' || exp[i]==')'){
				char t=pop();
				if(t=='{' && exp[i]!='}'){
					flag=false;
					break;
				}
				else if(t=='[' && exp[i]!=']'){
					flag=false;
					break;
				}
				else if(t=='(' && exp[i]!=')'){
					flag=false;
					break;
				}
			}
		}
		if(flag==true){
			cout<<"Expression is balanced.\n";
		}
		else{
			cout<<"Expression is not balanced!\n";
		}
	}

};

int main() {
	char flag='y';
	while(flag=='y'){
		Stack s;
		s.checkExpression();
		cout<<"Check another expression(y/n): ";
		cin>>flag;
	}
	return 0;
}
