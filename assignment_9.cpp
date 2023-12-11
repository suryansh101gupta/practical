#include<iostream>
#include<string.h>
using namespace std;
#define MAX 100

class stack{
    public:
        int top;
        char a[MAX];
    public:
        stack(){
            top = -1;
        }
        bool push(char x){
            if(top>=MAX-1){
                cout<<"stack overflow"<<endl;
                return false;
            }
            else
                a[++top]=x;
                return true;
        }
        bool isEmpty(){
            return (top<0);
        }
        char peek(){
            return a[top];
        }
        char pop(){
            if(top<0){
                return 0;
            }
            else 
                return a[top--];
        }
};

int main(){
    stack s;
    string exp;
    cout<<"enter"<<endl;
    cin>>exp;
    bool flag = 0;
    char str[exp.length()+1];
    strcpy(str, exp.c_str())
    for(int i=0; i<exp.length(); i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{' ){
            s.push(str[i]);
        }
        if(str[i]==')' || str[i]==']' || str[i]=='}'){
            char t = s.pop();
            if(str[i]==')' && t=='(')
                continue;
            if(str[i]==']' && t=='[')
                continue;
            if(str[i]=='}' && t=='{')
                continue;
            flag = 1;
            break;
        }
    }
    if (flag == 1 || !s.isEmpty()){
        cout<<"incorrect"<<endl;
    }
    else{
        cout<<"correct"<<endl;
    }
    
    return 0;
}