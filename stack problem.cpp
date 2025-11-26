#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    
    Node(char d) {
        data = d;
        next = nullptr;
    }
};

class Stack{
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char c) {
        Node* newNode = new Node(c);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            return 0;
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};


bool isHalfReversible(string s) {

  /* check for length  even*/
    if (s.length() % 2 != 0) {
        return false;
    }
    int mid = s.length() / 2;
    Stack stack;

    // push first half into stack
    for (int i = 0; i < mid; i++) {
        stack.push(s[i]);
    }

    //compare with second half
    for (int i = mid; i < s.length(); i++) {
        char popped = stack.pop();
        if (popped != s[i]) {
            return false;
        }
    }

    return true;
}

int main() {

    string input;
    cout << "Enter string: ";
    cin >> input;

    if (isHalfReversible(input)) {
        cout << input << "  VALID \n";
    } else {
        cout << input << " NOT Half Reversible\n";
    }

    return 0;
}
// output: Enter string: racecar
//racecar NOT Half Reversible 
//Enter string: noon
//noon  VALID 

