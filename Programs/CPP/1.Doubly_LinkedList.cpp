#include <iostream>
using namespace std;

class LinkedList;

class Node{
    friend class LinkedList;
    int data;
    Node* next;
    Node* prev;
};

class LinkedList{
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void insertatEnd(int val){
        Node* newNode = new Node();
        newNode -> data = val;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;

        if(head == nullptr){
            head = newNode;
            tail = newNode;
            newNode ->prev = nullptr;
        }else{
            tail -> next = newNode;
            newNode -> prev = tail;
            newNode -> next = nullptr;
            tail = newNode;
        }
    }

    void insertatStart(int val){
        Node* newNode = new Node();

        newNode -> data = val;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;

        if(tail == nullptr){
            head = nullptr;
            tail = nullptr;
            newNode -> next = nullptr;
            newNode -> prev = nullptr;
        }else{
            head -> prev = newNode;
            newNode -> next = head;
            newNode -> prev = nullptr;
            head = newNode;
        }

    }


    void display(){
        Node* temp = head;
        cout << "----------------------" << endl;
        while(temp != nullptr){
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }

        cout << "null" << endl;
        cout << "----------------------\n\n" << endl;
    }

    void displayfromtail(){
        Node* temp = tail;
        cout << "Display from tail" << endl;
        cout << "----------------------" << endl;
        while(temp != nullptr){
            cout << temp -> data << " -> ";
            temp = temp -> prev;
        }

        cout << "Null" << endl;
        cout << "----------------------\n\n" << endl;
    }

    void deleteNode(int val){
        Node* temp = head;

        while(temp != nullptr && temp -> data != val){
            temp = temp -> next;
        }

        if(temp == nullptr){
            cout << "Element not Found" << endl;
        }else{
            if(temp == head){
                temp -> next -> prev = nullptr;
                head = temp -> next;
                cout << "Deleted: " << val << " from head" << endl;
                display();
            }else if(temp == tail){
                temp -> prev -> next = nullptr;
                tail = temp -> prev;
                cout << "Deleted: " << val << " from tail" << endl;
                display();
            }else{
                temp -> prev -> next = temp -> next;
                cout << "Deleted: " << val << " from middle" <<  endl;
                display();
            }
        }

    }
};

int main()
{
    LinkedList list1;

    list1.insertatEnd(2);
    list1.insertatEnd(3);
    list1.insertatEnd(4);
    list1.insertatEnd(5);
    list1.insertatEnd(6);
    list1.insertatEnd(7);
    list1.insertatEnd(8);
    list1.insertatEnd(9);
    list1.display();

    cout << "insert at start 01" << endl;
    list1.insertatStart(1);
    list1.insertatStart(0);

    list1.display();
    list1.displayfromtail();

    list1.deleteNode(0); // From Head
    list1.deleteNode(7); // From Middle
    list1.deleteNode(9); // From End


}
