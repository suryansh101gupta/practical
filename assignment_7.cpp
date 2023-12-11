#include<iostream>
#include<string.h>
using namespace std;

class node{
    public:
    int status;
    int seat;
    node *next;
    node *prev;

};

class linklist{
    public:
    node *head, *tail, *temp;
    // node *temp = new node;
    linklist(){head = temp = NULL;}
    void createlist();
    void book();
    void delt();
    void display();
    void avail();
};


int main(){
    linklist l;
    l.createlist();
    int flag = 1;
    int ch;
    while(flag){
        l.display();
        cout<<"\nmenu"<<endl;
        cout << "\nEnter Choice\n1.Current Seat Status\n2.Book Seat \n3.Available Seat\n4.CancelSeat\n";
        cin>> ch;
        switch(ch){
            case 1:
                l.display();
                break;
            case 2:
                l.book();
                break;
            case 3:
                l.avail();
                break;
            case 4:
                l.delt();
                break;
            default:
                cout<<"INVALID"<<endl;
        }
        cout << endl<<"Do you want to perform any other operation? (1 for yes/0 for no): ";
        cin >> flag;
    }
    return 0;
}


void linklist ::createlist(){
    node *temp = new node;
    temp->status=0;
    temp->seat=1;
    tail = head = temp;
    for(int i=2; i<=70; i++){
        node *t = new node;
        t->status=0;
        t->seat=i;
        tail->next=t;
        t->prev=tail;
        tail=t;
        t->next=head;
        head->prev=tail;
    }
}

void linklist::book(){
    int no;
    cout<<"which seat"<<endl;
    cin>>no;
    if(no>0 && no<=70){
        temp = head;
        while(temp->seat!=no){
            temp=temp->next;
        }
        temp->status=1;
        cout<<endl;
        cout<<"seat : "<<no<<" booked."<<endl;
    }
    else{
        cout<<"invalid"<<endl;
    }
}


void linklist :: display(){
    int i=1;
    temp = head;
    while(temp->next!=head){
        if(temp->seat/10 == 0){
            cout<<"S0"<<temp->seat;
        }
        else{
            cout<<"S"<<temp->seat;
        }

        if(temp->status==0){
            cout<<"|___|";
        }
        else{
            cout<<"|_B_|";
        }

        if(i%7==0){
            cout<<endl;
        }
        temp=temp->next;
        i++;
    }
    cout<<"S"<<temp->seat;
    if(temp->status==0)
        cout<<"|___|";
    else
        cout<<"|_B_|";
}

void linklist :: delt(){
    int no;
    cout<<"which seat"<<endl;
    cin>>no;
    if(no>0 && no<=70){
        temp = head;
        while(temp->seat!=no){
            temp=temp->next;
        }
        temp->status=0;
        cout<<endl;
        cout<<"seat : "<<no<<" deleted."<<endl;
    }
    else{
        cout<<"invalid"<<endl;
    }
}

void linklist :: avail(){
    int no;
    cout<<"which seat"<<endl;
    cin>>no;
    if(no>0 && no<=70){
        temp->seat = no;
        if(temp->status == 0){
            cout<<"available";
        }
        else
            cout << "\nBooked";
        
    }
    else
        cout << "\nSeat Number out of range!" << endl;
}