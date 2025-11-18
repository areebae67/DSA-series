#include<iostream>
using namespace std;

struct Node{
int data;
Node* next;
};

class Stack{
    private: 
    Node* top;
    public:
    Stack(){
        top = NULL;
    }

    void push(int val){
        Node* newNode = new Node();
        newNode->data= val;
        newNode->next =top;
        top = newNode;

        cout<<"value " <<val<<"pushed.\n";
    }

void pop(){
    if (top == NULL){
        cout<<"stack is empty.";
        return;
    }
    Node* temp= top;
    top = top->next;
    cout << temp->data << " popped.\n";
    delete temp;
}
/* Peek (Show top element) */
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }
    /* Display stack */
    void display() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }

        Node* temp = top;
        cout << "Stack (top to bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
/* MAIN */
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();  

    s.pop();
    s.display();   

    s.peek();      

    return 0;
}
/*  
value 10pushed.
value 20pushed.
value 30pushed.
Stack (top to bottom): 30 20 10 
30 popped.
Stack (top to bottom): 20 10    
Top element: 20 */
