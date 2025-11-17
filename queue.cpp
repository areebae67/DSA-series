#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class Queue {
private:
 Node* front;
 Node*rear;
public:
 Queue(){
    front=rear=NULL;
 }

 /* Insert from rear*/
 void enqueue(int val) {
    Node* newNode= new Node();
    newNode->data=val;
    newNode->next=NULL;

    if(rear == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    cout<<val <<" enqueued.\n"<<endl;
 }

 /*Delete from front*/

 void dequeue() {
    if(front== NULL){
        cout<<"queue is empty cannont delete! ";
        return;
    }
    Node * temp = front;
    front = front->next;
    if(front== NULL) {
        rear = NULL;
    }
    cout<<temp->data<<" dequeued.\n ";
    delete temp;
 }

 /* Peek front element */
    void peek() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }


    /* Display queue */
    void display() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};
/* MAIN */
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();  // 10 20 30
  
    q.dequeue();
    q.display();  // 20 30

    q.peek();     // 20

    return 0;
}
