#include<iostream>
// #include<string.h>
using namespace std;

class stack{
    public:
    char stac[20];
    int top = -1;
    char exp[30];
    char postfix[30];
    int k = 0;

    public:
    stack(){
        cout<<"enter expression"<<endl;
        cin>>exp;
    }
    int priority(char ch){
        if (ch == '+') return 1;
        else if (ch == '-') return 1;
        else if (ch == '/') return 2;
        else if (ch == '*') return 2;
        else return -1;
    }
    void push(char ch){
        if (top<9){
            top++;
            stac[top]=ch;
    }}
    char pop(){
        if (top == -1){
            return 0;}
        else{
            char popped = stac[top];
            top--;
            return popped;}
            // return stack[top--];
            return '\0';
    }
    char peek(){
        if (top != -1){
            return stac[top];
        }
        return '\0';
    }
    bool isEmpty(){
        return top == -1;
    }
};


int main(){
    stack s;
    for(int i = 0; s.exp[i] != '\0' ; i++ ){                      //PLEASE REVIEW
        char ch = s.exp[i];
        if((ch == '(') || (ch == '{') || (ch == '[')){
            s.push(ch);
        }
        else if((ch==')') || (ch==']') || (ch=='}')){
            while(!s.isEmpty() && (s.peek() != '(' && s.peek() != '[' && s.peek() != '{')   ){
                s.postfix[s.k] = s.pop();
                s.k++;
                i--;
            }
            if (!s.isEmpty()) {
                s.pop();
            }
        }
        else if((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')){
            if(!s.isEmpty() && (s.priority(s.peek())>=s.priority(ch))){
                s.postfix[s.k]=s.pop();
                s.k++;
                i--;
            }
            else{
                s.push(ch);
            }   
        }
        else{
            s.postfix[s.k]=ch;
            s.k++;
        }
    }
        while(!s.isEmpty()){
            s.postfix[s.k]=s.pop();
            s.k++;
        }
        s.postfix[s.k]='\0';
        cout<<"postfix expression : "<<s.postfix<<endl;


        s.k=0;
        s.top=-1;
        while(s.postfix[s.k]!='\0'){
            switch(s.postfix[s.k]){
                case '+':
                    s.push(char((s.pop() - '0') + (s.pop() - '0') + '0'));
                    break;
                case '-':
                    s.push(char((s.pop() - '0') - (s.pop() - '0') + '0'));
                    break;
                case '*':
                    s.push(char((s.pop() - '0') * (s.pop() - '0') + '0'));
                    break;
                case '/':
                    s.push(char((s.pop() - '0') / (s.pop() - '0') + '0'));
                    break;
                default:
                    s.push(s.postfix[s.k]);
                    break;
            }
            s.k++;
        }
        cout<<"answer : "<<s.peek() - '0' <<endl;
        return 0;
}
