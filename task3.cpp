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
        cout<<"NULL";
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
    

};




int main(){
    list numbers;
    numbers.printSecondNode();
    numbers.addNode(1);
    numbers.printSecondNode();
    // the values are taken from user within the function as the syntax for the fuction state in the document file
    numbers.createThreeNodes(); 
    numbers.searchNode(20);
    numbers.searchNode(99);

    numbers.clearList(); //releasing the memory









    return 0 ;
}