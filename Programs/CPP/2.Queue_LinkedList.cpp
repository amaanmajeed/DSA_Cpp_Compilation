#include <iostream>
using namespace std;

class Node{
    friend class Queue;
    int data;
    Node* next;
};


class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    void insertNode(int val){// End
        Node* newNode = new Node();
        newNode -> data = val;
        newNode -> next = nullptr;

        if(tail == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void Deleteathead(){    // head
        Node* curr = head;
        if(head == nullptr){
            cout << "Queue Empty" << endl;
        }else{
            cout << "\nDeleted " << head -> data << endl;
            head = head -> next;
            display();
        }
        delete curr;
        curr = nullptr;
    }


    void display(){
        Node* curr = head;
        cout << "----------------------------" << endl;
        while(curr != nullptr){
            cout << curr -> data << " -> ";
            curr = curr -> next;
        }
        cout << "End" << endl;
        cout << "----------------------------" << endl;
    }

};

int main()
{
    Queue q1;

    q1.insertNode(1);
    q1.insertNode(2);
    q1.insertNode(3);
    q1.insertNode(4);
    q1.insertNode(5);

    q1.display();


    q1.Deleteathead();
    q1.Deleteathead();
    q1.Deleteathead();
    q1.Deleteathead();
    q1.Deleteathead();
    q1.Deleteathead();

}
