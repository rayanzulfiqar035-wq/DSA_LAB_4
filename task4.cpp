#include<iostream>
using namespace std ;

class list {
private :
    struct node{
        int data ;
        node* next;

        node(int value){
            data = value;
            next = NULL;
        }
    };

public :
    node* head = NULL;

    void createThreeNodes(){  //assuming the list is empty at first
        int val1;
        int val2;
        int val3;
        cout<<"Enter the data of three nodes : \n";
        cin>>val1;
        cin>>val2;
        cin>>val3;

        node* n1 = new node(val1);
        node* n2 = new node(val2);
        node* n3 = new node(val3);
        head = n1;
        n1->next = n2;
        n2->next = n3;
        n3->next = NULL;
    }

    void printList(){
        node* curr = head;
        if(head == NULL){
            cout<<"List is Empty\n";
            return ;
        }
        while(curr != NULL){
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }
        cout<<"NULL"<<endl;

    }

    void clearList(){
        if(head == NULL){
            cout<<"List is ALready Empty.\n";
            head = NULL;
            return;
        }
        node* curr = head;
        node* temp = head->next;
        while(temp!=NULL){
            delete curr;
            curr = temp;
            temp = temp->next;
        }

        head =NULL;
        
    }

    void addNode(int data){
        node* add = new node(data);
        node* curr = head;
        node* prev = NULL;
        if(head == NULL){
            head = add ;
            add->next = NULL;
            return;
        }
        while(curr!=NULL){
            prev = curr;
            curr = curr->next;
        }

        curr = add ;
        prev->next = add;
        add->next = NULL;

    }

    void insertAtTheBeginning(int addData){

        node* start = new node(addData);
        start->next = head;
        head = start;
    }
    

};


int main(){

    list numbers;
    numbers.insertAtTheBeginning(20);
    numbers.printList();
    numbers.insertAtTheBeginning(10);
    numbers.printList();
    numbers.addNode(30);
    numbers.printList();

    numbers.clearList();  // releasing the memory






    return 0 ;
}