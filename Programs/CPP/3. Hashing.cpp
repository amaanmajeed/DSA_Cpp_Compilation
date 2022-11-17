#include <iostream>
#include<list>
#include<iterator>

using namespace std;

class Hashing
{
    list<int> *table;
    int total_elements;

    int gethash(int key)
    {
        return key % total_elements;
    }

public:
    Hashing(int n)
    {
        total_elements = n;
        table = new list<int>[total_elements];
    }

    void insertelement(int key)
    {
        table[gethash(key)].push_back(key);
    }

    void printall()
    {
        for(int i = 0; i < total_elements; i++)
        {
            cout << "Index " << i << ": ";
            for(int j : table[i])
                cout << j << " -> ";
            cout << "END" << endl;
        }
        cout << endl;
    }



    void search_val(int key)
    {
        int counting = 0;
        int x = gethash(key);
        list<int>::iterator i;

        for(i = table[x].begin();i != table[x].end(); i++)
        {
            if(*i == key)
            {
                break;
            }
            counting++;
        }
        if(i != table[x].end())
            cout << "Found at index " << x << " after counting " << counting << " times" << endl;
        else
            cout << "NOT FOUND" << endl;
    }

    void removeval(int key)
    {
        int x = gethash(key);
        list<int>::iterator i;

        for(i = table[x].begin();i != table[x].end(); i++)
        {
            if(*i == key)
                break;
        }
            if(i != table[x].end())
            {
                table[x].erase(i);
                cout << "Element deleted" << endl;
            }
            else
                cout << "Element not found" << endl;

    }

};

int main()
{
    Hashing ht(3);

    ht.insertelement(2);
    ht.insertelement(4);
    ht.insertelement(6);
    ht.insertelement(8);
    ht.insertelement(10);
    ht.insertelement(12);
    ht.insertelement(14);

    ht.printall();

    ht.search_val(14);

    ht.removeval(10);
    ht.printall();

}
