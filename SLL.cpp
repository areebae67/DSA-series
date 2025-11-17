
/*Singly Linked List basic implementation*/
#include <iostream>
using namespace std;

struct Node 
{
    int data;
     Node* next;
    
};
Node* head= NULL;
/* insert at begin*/
Node* insertatbegin(Node*head,int info){
    Node * newNode = new Node();
    newNode-> data=info;
    newNode->next = head;
    return newNode;
}

/*Insert at end*/
Node* insertatend(Node* head,int info){
    Node* newNode = new Node();
    newNode->data=info;
    newNode->next=NULL;
    if (head == NULL){
        return newNode;
    }

    Node *temp =head;
    while (temp->next!=NULL) {
        temp= temp->next;
    }
    temp->next= newNode;
    return head;
}

/*insert after a given value x */

Node* insertafter(Node*head,int x,int info){
Node* ptr=head;
Node* newNode;
newNode= new Node();
newNode->data=info;
newNode->next= NULL;

while (ptr != NULL && ptr->data !=x)
{
    ptr = ptr->next;
}
 if(ptr == NULL) {
        cout << "Value not found!" << endl;
        return head;
    }

    newNode->next= ptr->next;
    ptr->next= newNode;
    return head;

}

/*delete first node */

Node* deletefirst(Node* head){

    if(head==NULL){
        cout<<"list is empty!";
        return head;
    }
  
     Node* temp= head;
     head= head->next;
     delete temp;
     return head;
}

/*delete last node*/

Node* deletelast(Node* head){
    Node* temp;
    Node* pretemp;
    /*case 1: */
if(head==NULL){
        cout<<"list is empty!";
        return head;
    }
    /*case 2: */
    if(head->next==NULL){
        delete head;
        return NULL;
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

    /*delete after a given position*/

    Node* deleteafter(Node*head,int key){
        Node*temp1;
        Node*temp2;
        if(head==NULL){
        cout<<"list is empty!";
        return head;
    }
    temp1=head;
    while(temp1->next != NULL){
        if (temp1->data==key)
        {
            temp2=temp1->next;
            temp1->next=temp2->next;
            delete temp2;
            return head;
        }
        temp1=temp1->next; 
    }
    cout << "Key not found!" << endl;
    return head;
    }

    /* delete a given node*/
     Node* deletenode(Node*head,int key){
        Node*temp1;
        Node*temp2;

        if(head==NULL){
        cout<<"list is empty!";
        return head;
    }

    temp1=head;
    temp2=head->next;
    while (temp2->data==key){
        temp1->next=temp2->next;
        delete temp2;
        return head;
    }
    temp1=temp2;
    temp2=temp2->next;

    if (temp2 == NULL) {
        cout << "Value not found!" << endl;
        return head;
    }
}
/* delete all nodes */
     Node* deleteall(Node*head){
        Node*temp;
        temp=head;
        while (temp!=NULL)
        {
            temp= temp->next;
            delete head;
            head = temp;
        }
        return NULL;

    }

/* Traverse function*/
void traverse( Node* head) {
    if (head == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    Node*ptr = head;
    cout<<"Linked list:";
    while (ptr!= NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
    
}
/*Main implementation*/

int main() {
    head = insertatbegin(head, 10);
    head = insertatbegin(head, 20);
    head = insertatend(head, 30);
    head = insertafter(head, 20, 25);

    traverse(head);

    head = deletefirst(head);
    traverse(head);

    head = deletelast(head);
    traverse(head);

    head = deleteafter(head, 20);
    traverse(head);

    head = deletenode(head, 10);
    traverse(head);

    head = deleteall(head);
    traverse(head);

    return 0;
} /*Linked list:20 25 10 30
Linked list:25 10 30
Linked list:25 10
Key not found!
Linked list:25 10
Linked list:25
List is empty!*/




