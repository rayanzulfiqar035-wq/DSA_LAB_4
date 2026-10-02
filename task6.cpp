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

    //part of task 1
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

    //part of task 2
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


    //part of task 3
    void printSecondNode(){
        if(head == NULL){
            cout<<"List is empty."<<endl;
            return;
        }

        if(head->next == NULL){
            cout<<"The list contain only one node.\nNO second node."<<endl;
            return;
        }

        else{
            cout<<"The Data Value at the 2nd node is : "<<(head->next)->data<<endl;
        }
    }
    
    


    void searchNode(int target){   // starting counting from 1
        if(head == NULL){
            cout<<"List is Empty. Not found";
            return;
        }
        node* curr = head;
        int count = 1;
        while(curr!= NULL){
            if(curr->data == target){
                cout<<"The target node is at "<<count<<" position."<<endl;
                return;
            }

            curr = curr->next;

            count++;
        }

        cout<<"Targeted value not found."<<endl;
        
    }

    //task 4 
    void insertAtTheBeginning(int addData){

        node* start = new node(addData);
        start->next = head;
        head = start;
    }
    
    //task 5
    void deleteNode(int delData){
        if(head == NULL){
            cout<<"The List is empty."<<endl;
            return;
        }
        if(head->next == NULL && head->data == delData){
            delete head;
            cout<<"List contained only one element which is now Deleted"<<endl;
            head=NULL;
            return;
        }
        node* curr = head;
        node* prev = nullptr;
        
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

int main(){
    list numbers;
    char choice;   // use charator for selection because it is easy to validate
    bool exit = false;
    while(true){
        cout<<"Choose an operation from (a-h) "<<endl;
        cout<<"a. Insert at the beginning\nb. Insert at the end\nc. Search by value\nd. Delete by Value\ne. Display all nodes\nf. Count nodes\ng. Display 2nd node\nh. Exit\nEnter Your Choice : ";
        cin>>choice;
        if(tolower(choice) >= 'a' && tolower(choice) <= 'h'  && isalpha(choice)){
            switch (choice) {
                case 'a':
                    int data;
                    cout<<"Enter the data : ";
                    cin>>data;
                    numbers.insertAtTheBeginning(data);
                    cout<<"-----------------------\n";
                    break;
                case 'b' :
                    int val;
                    cout<<"Enter the data : ";
                    cin>>val;
                    numbers.addNode(val);
                    cout<<"-----------------------\n";
                    break;
                case 'c' :
                    int value;
                    cout<<"Enter the targeted data : ";
                    cin>>value;
                    numbers.searchNode(value);
                    cout<<"-----------------------\n";
                    break;
                case 'd' :
                    int nodeData;
                    cout<<"Enter the node's data : ";
                    cin>>nodeData;
                    numbers.deleteNode(nodeData);
                    cout<<"-----------------------\n";
                    break;
                case 'e' :
                    numbers.printList();
                    cout<<"-----------------------\n";
                    break;
                case 'f' :
                   cout<<"Number of Nodes : "<< numbers.countNodes()<<endl;
                   cout<<"-----------------------\n";

                    break;
                case 'g' :
                    numbers.printSecondNode();
                    cout<<"-----------------------\n";

                    break;
                case 'h' :
                    numbers.clearList();
                    cout<<"Deleting Dynamic Nodes"<<endl;
                    cout<<"Logging Out...."<<endl;
                    cout<<"-----------------------\n";
                    exit = true;
                    break;
            }

                if(exit){
                    break;
                }
        }
        else{
            cout<<"INVALID Choice"<<endl;
        }
    }


    return 0 ;
}