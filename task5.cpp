// Name : Muhammad Rayan Zulfiqar
// CMS : 543021
//Section : BScs 15-D


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

    int countNodes(){
        int count = 0 ;
        node* curr= head;
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        return count;
    }

    void insertAtTheBeginning(int addData){

        node* start = new node(addData);
        start->next = head;
        head = start;
    }

    void deleteNode(int delData){
        if(head == NULL){
            cout<<"The List is empty."<<endl;
            return;
        }
        if(head->next == NULL && head->data == delData){
            delete head;
            cout<<"List contained only one element which is now Deleted"<<endl;
            head = NULL;
            return;
        }
        node* curr = head;
        node* prev = nullptr;
        if(curr->data == target){
            head = curr->next ;
            delete curr;
            return;
        }
        
        while(curr!=NULL){
            if(curr->data == delData){
                prev->next = curr->next;
                delete curr;
                cout<<"Deleted"<<endl;
                return;
            }
            prev = curr;
            curr = curr->next;

        }

        cout<<"Target Not found."<<endl;
    }
    

};

int main (){
    list numbers;
    //for empty list
    numbers.deleteNode(30);

    //for single node
    numbers.addNode(30);
    numbers.printList();
    numbers.deleteNode(30);
    numbers.printList();

    //testing for multiple nodes
    numbers.addNode(10);
    numbers.addNode(20);    
    numbers.addNode(20);    
    numbers.addNode(30);
    numbers.printList();
    numbers.deleteNode(20);
    numbers.printList();

    numbers.clearList();  //releasing memory



    return 0 ;
}
