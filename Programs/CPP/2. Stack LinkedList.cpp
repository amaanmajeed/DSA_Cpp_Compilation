#include <iostream>
using namespace std;

class Node{
    friend class Stack;
    int data;
    Node* prev;
};

class Stack{
    Node* top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int val)
    {
        Node* newNode = new Node();
        newNode -> data = val;
        newNode -> prev = top;
        top = newNode;
        cout << "Added: " << val << endl;
    }

    void pop(int& val){
        val = top -> data;
        top = top -> prev;
    }


};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    int value;
    s1.pop(value);
    cout << "Retrieved " << value << endl;
    s1.pop(value);
    cout << "Retrieved " << value << endl;

}
