#include <iostream>
#include <string.h>
using namespace std;

class queue{
    int que[100];
    int * arr;
    int front;
    int rear;
    int n;
    int i;
    int data;

    public:
        queue(){
            n = 100001;
            arr = new int[n];
            front = 0;
            rear = 0;
        }

        void insert(){
            if(rear==n){
                cout<<"q full"<<endl;
            }
            else{
                if(front==0){
                    front++;
                }
                cout<<"enter element"<<endl;
                cin>>data;
                rear++;
                arr[rear]=data;
                
            }
        }
        
        int delt(){
            if(front == 0 || front>rear){
                cout<<"q underflow"<<endl;
            } 
            else{
                // arr[front]=-1;
                cout<<"ele delt = "<<arr[front]<<endl;
                front++;
                if(front == rear ){
                    front = 0;
                    rear = 0;
                }
            }
        }

        bool isEmpty(){
            if(front == rear){
                return true;
            }
            else{
                return false;
            }
        }

        int qfront(){
            if(front == rear){
                return -1;
            }
            else{
                return arr[front];
            }
        }

        int display(){
            if(front == 0){
                cout<<"q empty"<<endl;
            }
            else{
                for(int i=front;i<=rear;i++){
                    cout<<"this is element "<<i<<" : "<<arr[i]<<endl;
                }
            }
        }

};

int main(){
    queue q;
    int ch;
    int flag = 1;
    while(flag){
        cout<<"menu"<<endl;
        cout<<"1.insert"<<endl;
        cout<<"2.delete"<<endl;
        cout<<"3.display"<<endl;
        // cout<<"4.exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                q.insert();
                break;
            case 2:
                q.delt();
                break;
            case 3:
                q.display();
                break;
            // case 4:
            //     q.exit();
            //     break;
            default:
                cout<<"invalid"<<endl;
        }
        cout << "Do you want to continue? (1 for yes/0 for no): ";
        cin >> flag;
    }
    return 0;
}