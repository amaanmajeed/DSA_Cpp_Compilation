#include <iostream>
using namespace std;

class Stack
{
    int sizes;
    int top;
    int* arr;
public:
    Stack(int sizes)
    {
        this -> sizes = sizes;
        arr = new int[sizes];
        top = -1;
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        else
            return false;

    }

    bool isFull()
    {
        if(top == (sizes-1))
            return true;
        else
            return false;
    }

    bool push(int val)
    {
        if(isFull())
            return false;
        else
        {
            top++;
            arr[top] = val;
            return true;
        }
    }

    bool pop(int& val)
    {
        if(isEmpty())
            return false;
        else
        {
            val = arr[top];
            top--;
            return true;
        }
    }
};

int main()
{
    Stack s1(5);
    if(s1.push(1)){
        cout << "successfully pushed: 1" << endl;
    }else{
        cout << "Unable to push" << endl;
    }

    int val;
    if(s1.pop(val)){
        cout << "Value: " << val << endl;
    }else{
        cout << "Unable to retrieve data" << endl;
    }
}
