#include <iostream>
using namespace std;

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

    void insertatend(int val){
        Node* newNode = new Node();

        newNode -> data = val;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    void insertatstart(int val){
        Node* newNode = new Node();

        newNode -> data = val;
        newNode -> prev = nullptr;

        if(tail == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            head -> prev = newNode;
            newNode -> next = head;
            head = newNode;
            cout << "\nAdded: " << val << " in the start" << endl;
            display();
        }
    }

    void display(){
        Node* curr = head;
        cout << "--------------------------------------------------------" << endl;
        while(curr != nullptr){
            cout << curr -> data << " -> ";
            curr = curr -> next;
        }
        cout << "End" << endl;
        cout << "--------------------------------------------------------" << endl;
    }


    void opdisplay(){
        Node* curr = tail;
        cout << "\nDisplay Opposite" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "END";
        while(curr != nullptr){
            cout  <<  " <- " << curr -> data;
            curr = curr -> prev;
        }
        cout << "\n--------------------------------------------------------" << endl;
    }


    void DeleteNode(int val){
        Node* curr = head;
        while(curr != nullptr && curr -> data != val){
            curr = curr -> next;
        }

        if(curr == nullptr){
            cout << "Could not find: " << val << endl;
        }else{
            if(curr == head){
                head = head -> next;
                head -> prev = nullptr;
                cout << "Deleted: " << val << " from head" << endl;
            }else if(curr == tail){
                tail = tail -> prev;
                tail -> next = nullptr;
                cout << "Deleted: " << val << " from tail" << endl;
            }else{
                curr -> next -> prev = curr -> prev;
                curr -> prev -> next = curr -> next;
                cout << "Deleted: " << val << " from middle" << endl;
            }
                delete curr;
                curr = nullptr;
        }
    }



    void searchNode(int val){
        Node* curr = head;
        int pos = 0;
        while(curr != nullptr && curr -> data != val){
            curr = curr -> next;
            pos++;
        }

        if(curr == nullptr){
            cout << "Could not find: " << val <<endl;
        }else{
            cout << "Found: " << curr -> data << " at Position: " << pos << endl;
        }
    }

    void Update(int val,int newval){
        Node* curr = head;

        while(curr != nullptr && curr -> data != val){
            curr = curr -> next;
        }

        if(curr == nullptr){
            cout << "Could not find: " << val <<endl;
        }else{
            curr -> data = newval;
            cout << "Found: " << val << " Replaced with: " << curr -> data << endl;
            display();
        }
    }

    void removeFromLast(){
        Node* temp = tail;
        cout << "\nRemove From Last" << endl;
        cout << "Deleted: " << temp -> data << " From last" << endl;
        tail = tail -> prev;
        tail -> next = nullptr;
        delete temp;
        temp = nullptr;
        display();
    }

    void removeFromStart(){
        Node* temp = head;
        cout << "\nRemove From Last" << endl;
        cout << "Deleted: " << temp -> data << " From Start" << endl;
        head = head -> next;
        head -> prev = nullptr;
        delete temp;
        temp = nullptr;
        display();
    }

    void removeSecondLastNode(){
        Node* curr = tail -> prev;
        cout << "\nRemove Second Last Node" << endl;
        curr -> next -> prev = curr -> prev;
        curr -> prev -> next = curr -> next;
        cout << "Deleted: " << curr -> data << " Second Last Node" << endl;

        delete curr;
        curr = nullptr;

        display();
    }


};

int main(){

    LinkedList list1;
    list1.insertatend(3);
    list1.insertatend(4);
    list1.insertatend(5);
    list1.insertatend(6);
    list1.insertatend(7);
    list1.insertatend(8);
    list1.insertatend(9);
    list1.insertatend(10);
    list1.insertatend(11);
    list1.insertatend(12);

    cout << "Display" << endl;
    list1.display();


    list1.insertatstart(2);
    list1.insertatstart(1);

    list1.opdisplay();

    cout << "\nDelete By passing Value" << endl;
    cout << "--------------------------------------------------------" << endl;
    list1.DeleteNode(1); // Delete At start
    list1.DeleteNode(5); // delete at mid
    list1.DeleteNode(8); // Delete at end
    list1.DeleteNode(12); //Not Found
    cout << "--------------------------------------------------------" << endl;

    list1.display();


    list1.removeFromLast();
    list1.removeFromStart();
    list1.removeSecondLastNode();

    list1.searchNode(7); // search

    list1.Update(3,30);


}
