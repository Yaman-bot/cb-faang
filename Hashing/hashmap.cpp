#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;

    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
            delete next;
    }
};

template <typename T>
class Hashtable
{
    Node<T> **table;
    int currentSize;
    int tableSize;

    int hashFn(string key)
    {
        int idx = 0;
        int p = 1;
        //mod so many times as a large number can cause overflowing which may lead to -ve indexes
        // and that can lead to segmentation fault
        for (int j = 0; j < key.length(); j++)
        {
            idx = idx + (key[j] * p) % tableSize;
            idx = idx % tableSize;
            p = (p * 27) % tableSize;
        }
        return idx;
    }

    void rehash()
    {
        Node<T> **oldTable = table;
        int oldTableSize = tableSize;
        tableSize = 2 * tableSize;
        table = new Node<T> *[tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = NULL;
        }
        currentSize = 0;

        //Shift elements from old table to new table
        for (int i = 0; i < oldTableSize; i++)
        {
            Node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            //delete linked list
            if (oldTable[i] != NULL)
            {
                //will recursively delete nodes of LL as destructor is made in this way
                delete oldTable[i];
            }
        }

        //delete oldTable
        delete[] oldTable;
    }

public:
    Hashtable(int ts = 7)
    {
        tableSize = ts;
        table = new Node<T> *[tableSize];
        currentSize = 0;
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, value);

        //insert at head of linked list with id=idx
        n->next = table[idx];
        table[idx] = n;
        currentSize++;

        //Rehashing
        float loadFactor = currentSize / (1.0 * tableSize);

        if (loadFactor > 0.7)
            rehash();
    }

    void print()
    {
        for (int i = 0; i < tableSize; i++)
        {
            cout << "Bucket " << i << "->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next
            }
            cout << endl;
        }
    }

    T *search(string key)
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
                return &temp->value;
            temp = temp->next;
        }
        return NULL; //T*
    }

    //returning value box by reference
    T &operator[](string key)
    {
        T *f = search(key);
        if (f == NULL)
        {
            //insert key,value(garbage) in hashmap
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return *f;
    }
};