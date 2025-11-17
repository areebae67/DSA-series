#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node* prev;
    
};
class doublylist{
Node* head; 
Node* tail;
public: doublylist(){
    head = tail=NULL;
}


/*Insert a node at start*/

void push_front(int val){
    Node * newNode = new Node();
    newNode->data= val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head== NULL){
head= tail=newNode;
    }
    else {
        head->prev= newNode;
        head=newNode;
    }
}
/*Insert a node at end*/

void push_end(int val){
    Node * newNode = new Node();
    newNode->data= val;
    newNode->next = NULL;
    newNode->prev = tail;
    if(head== NULL ){
        head= tail=newNode;
    } else{ 
    tail->next= newNode;
    tail= newNode; }
}

/* Delete first node */
    void pop_front() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head= head->next;
        if(head!=NULL){
            head->prev=NULL;
           
        }else{ tail=NULL;}
         delete temp;
    }
 /* Delete last node */
    void pop_back() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        tail= tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
           
        } else{ head=NULL;}
          delete temp;
    }
/*display forward*/
void traverseforward(){
     if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Forward: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    /*display backward*/
    void traverseBackward() {
        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail;
        cout << "Backward: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
/* MAIN */
int main() {
    doublylist dl;

    dl.push_front(10);
    dl.push_front(20);
    dl.push_end(5);
    dl.push_end(1);

    dl.traverseforward();   // 20 10 5 1
    dl.traverseBackward();  // 1 5 10 20

    dl.pop_front();
    dl.traverseforward();   // 10 5 1

    dl.pop_back();
    dl.traverseforward();   // 10 5

    return 0;
}
/*output: Forward: 20 10 5 1 
Backward: 1 5 10 20
Forward: 10 5 1
Forward: 10 5*/



