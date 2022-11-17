#include <iostream>
using namespace std;

class Queue{
    int fronti;
    int rear;
    int* arr;

public:
    Queue(int sizes){
        arr = new int[4];
        fronti = -1;
        rear = -1;
        for(int i = 0; i < sizeof(arr);i++){
            arr[i] = 0;
            cout << i << " -> " << arr[i] << endl;
        }
    }

    ~Queue(){
        delete[] arr;
    }

    bool isEmpty(){
        if(fronti == -1 && rear == -1)
            return true;
        else
            return false;
    }
    bool isFull(){
        if(rear == sizeof(arr)-1){
            return true;
        }else{
            return false;
        }
    }


    void Enqueue(int val){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }else if(isEmpty()){
            rear = 0;
            fronti = 0;
            arr[rear] = val;
        }else{
            rear++;
            arr[rear] = val;
        }
    }

    int Dequeue(){
        int x = 0;
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return 0;
        }else if(fronti == rear){
            x = arr[fronti];
            arr[fronti] = 0;
            rear = -1;
            fronti = -1;
            return x;
        }else{
            x = arr[fronti];
            arr[fronti] = 0;
            fronti++;
            return x;
        }
    }

    int counter(){
        return (rear - fronti + 1);
    }

    void display(){
        cout << "-------------------------" << endl;
        for(int i = 0; i < sizeof(arr) ;i++){
            if(arr[i] != 0){
                cout << arr[i] << " -> ";
            }
        }
        cout << "End" << endl;
        cout << "-------------------------" << endl;
    }
};

int main()
{
    Queue q1(1);


    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Enqueue(4);
    q1.Enqueue(5);
    q1.Enqueue(6);
    q1.Enqueue(7);
    q1.Enqueue(8);

    q1.display();



    cout << endl;
    cout << "Counter: " << q1.counter() << endl;;

    if(q1.isEmpty()){
        cout << "Queue is Empty" << endl;
    }else{
        cout << "Queue s Not Empty" << endl;
    }

    if(q1.isFull()){
        cout << "Queue is full" << endl;
    }else{
        cout << "Queue is Not Full" << endl;
    }

    cout << endl << endl;

    cout << q1.Dequeue() << endl;
    cout << q1.Dequeue() << endl;
    cout << q1.Dequeue() << endl;
    cout << q1.Dequeue() << endl;

    q1.display();


    cout << endl;
    cout << "Counter: " << q1.counter() << endl;;

    if(q1.isEmpty()){
        cout << "Queue is Empty" << endl;
    }else{
        cout << "Queue s Not Empty" << endl;
    }

    if(q1.isFull()){
        cout << "Queue is full" << endl;
    }else{
        cout << "Queue is Not Full" << endl;
    }
}
