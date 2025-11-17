
/*Singly Linked List basic implementation*/
#include <iostream>
using namespace std;

struct Node 
{
    int data;
     Node* next; 
};
Node* head= NULL;

/* insert at start*/
Node* insertatbegin(Node*head,int info){
    Node * newNode = new Node();
    newNode-> data=info;
    newNode->next = head;
      head = newNode;
    return head;
}

/*Insert at end*/

Node* insertatend(Node* head,int info){
    Node* newNode = new Node();
    newNode->data=info;
    newNode->next=head;
    if (head == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    Node *temp =head;
    while (temp->next!=NULL) {
        temp= temp->next;
    }
    temp->next= newNode;
}

/*insert after a given position*/

Node* insertafter(Node*head,int x,int info){
Node* ptr;
Node* newNode;
newNode= new Node();
newNode->data=info;
newNode->next= NULL;
ptr=head;
while (ptr != NULL && ptr->data !=x)
{
    ptr = ptr->next;
}
if (ptr!=NULL && ptr->data == x)
{
    newNode->next= ptr->next;
    ptr->next= newNode;
} else {
    cout<<"value not found!";
}
return head;
}

/*delete at start*/

Node* deletefirst(Node* head){
    Node* temp;
    if(head==NULL){
        cout<<"list is empty!"
    }
    else{
        temp= head;
        head= head->next;
        delete temp;
    }
    return head;
}

/*delete at end*/
Node* deletelast(Node* head){
    Node* temp;
    Node* pretemp;
    /*case 1: */
if(head==NULL){
        cout<<"list is empty!";
    }
    /*case 2: */
    if(head->next==NULL){
        temp= head;
        delete temp;
        head=NULL;
    }
    /*Case 3: */
    temp=head;
    while (temp->next!= NULL)
    {
        pretemp= temp;
        temp= temp->next;
    }
    pretemp->next= NULL;
    delete temp;
    return head;
    }
