#include<bits/stdc++.h>
using namespace std;

//Node class: Actually it is used to create a Node dynnamically by using "new" keyword
class Node{
    public:
    int data;
    Node *next;
    //Constructor without any arguments
    Node(){
        this->next=NULL;
    }
    //Constructor with data as arguments
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
//Global Variable as we need head at every method
Node *head;

//Insert At begning Method
void insertAtBegning(int x){
    Node *temp=new Node(x);
    temp->next=head;
    head=temp;
}

//Insert at any position n
void insertAtNthPosition(int data,int position){
    //Creating a node 
    Node *temp=new Node(data);
    //handling begining position case
    if (position==1) {
        // here we can call insertAtBegning(data) also 
        temp->next=head;
        head=temp;
        return;
    }

    Node *temp2=head;
    for(int i=1;i<position-1;i++){
        temp2=temp2->next;
    }
    //trying to link from new node to (position + 1)node
    temp->next=temp2->next;
    //here trying to link (position - 1) node with position node which is new node
    temp2->next=temp;
}

void insertAtTail(int data){
    Node *temp=new Node(data);
    //This is when linked list is not containg any element
    if (head==NULL) {
        temp->next=head;
        head=temp;
        return;
    }
    //Going to last element
    Node *temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    //Connecting last element to newly created element
    temp2->next=temp;
}


void deleteAtNthPosition(int position){
    Node *temp=head;
    // handling first position 
    if(position==1){
        head=temp->next;
        free(temp);
        return;
    }

    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    Node *toBeDeleted=temp->next;
    temp->next=toBeDeleted->next;
    free(toBeDeleted);

}

//Print method
void print(int data){
    Node* temp=head;
    cout<<"List is:";
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

//PrintReverse method
void printReverse(Node *head){
    if(head != NULL){
        return;
    }
    printReverse(head->next);
    cout<<head->data<<"->";
}

//To reverse any singly linked list
Node* reverse(Node* head) {
    
    Node *previous,*current,*nextptr;
    current=head;
    previous=NULL;
    //iterative way
    while(current != NULL){
        nextptr=current->next;
        current->next=previous;
        previous=current;
        current=nextptr;
    }
    head=previous;
    return head;
}

int main(){

    //Creating a node head and initialing it with NULL
    head=new Node();
    head=NULL;

    int x,position,choice;
    bool run=true;
    //Taking n elements
    while(run){
        //Taking choice where to insert 
        cout<<"Enter your choice as => 1.insertAtBegning(), 2.insertAtNthPosition(),3.deleteAtNthPosition() AND 4.exit(): ";
        cin>>choice;
        switch(choice){
            case 1 :
                //Inserting at begining
                cout<<"Enter the elements to be inserted: ";
                cin>>x;
                insertAtBegning(x);
                break;
            case 2:
                //Inserting at any Nth position We can implement insertAtBegning() by here also we have to keep position=1
                cout<<"Enter the elements to be inserted: ";
                cin>>x;
                cout<<"Enter position where you want to place your element: ";
                cin>>position;
                insertAtNthPosition(x,position);
                break;

            case 3:
                cout<<"Enter position which you want to delete from linkedlist: ";
                cin>>position;
                //Deleting an Element From Any Position
                deleteAtNthPosition(position);
                break;
            default:
                run=false;
                cout<<"Thank You.";
                cout<<"Final ";
        }
        //Printing Value after every insertion
        print(x);
        printReverse(head);
    }
    return 0;
}
