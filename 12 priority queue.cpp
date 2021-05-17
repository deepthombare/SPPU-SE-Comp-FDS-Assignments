//============================================================================
// Name        : Priority Queue.cpp
// Author      : Deep Thombare
/*Assignment 12
 * Write program to implement a priority queue in C++ using an inorder list to store the items in the queue.
 * Create a class that includes the data items (which should be template)
 * and the priority (which should be int). The inorder list should contain these objects,
 * with operator <= overloaded so that the items with highest priority appear at the beginning of the list
 * (which will make it relatively easy to retrieve the highest item.)
 * */
#include <iostream>
using namespace std;

template <typename T>
class Item
{
private:
    int id;
    int priority;
    T data;
    Item<T> *next{NULL};

public:
    Item(int id, T data, int priority)
    {
        this->id = id;
        this->priority = priority;
        this->data = data;
    }

    int getPriority() const
    {
        return priority;
    }

    void setNext(Item<T> *nextItem)
    {
        this->next = nextItem;
    }

    Item<T> *getNext()
    {
        return next;
    }

    bool operator >=(const Item<T> i)
    {
        return priority >= i.getPriority();
    }

    void print()
    {
        cout << "\nJob id : " << this->id;
        cout << "\nJob data : " << this->data;
        cout << "\nJob priority : " << this->priority << endl;
    }
};

template <typename T>
class PriorityQueue
{
private:
    Item<T> *head{NULL}, *tail{NULL}, *temp{NULL}, *newNode{NULL}, *prev{NULL};

public:
    void enqueue(int id, T data, int priority)
    {
        if (head == NULL)
        { // queue is empty
            head = new Item<T>(id, data, priority);
            tail = head;
            cout << "\n>> Job Added to the Queue." << endl;
            return;
        }
        // insert the node at appropriate priority
        newNode = new Item<T>(id, data, priority);
        temp = head;
        prev = temp;
        while (temp != NULL && *newNode >= *temp)
        {
            prev = temp;
            temp = temp->getNext();
        }
        if (temp == NULL)
        {
            // newNode is now tail
            tail->setNext(newNode);
            tail = newNode;
        }
        else if (prev == temp)
        {
            // to be added as head
            newNode->setNext(head);
            head = newNode;
        }
        else
        {
            // middle insertion
            prev->setNext(newNode);
            newNode->setNext(temp);
        }
        cout << "\n>> Job Added to the Queue." << endl;
    }

    void dequeue()
    {
        if (head == NULL)
        {
            cout << "\n>> Queue Underflow!" << endl;
            return;
        }
        else if (head->getNext() == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            temp = head;
            delete head;
            head = temp->getNext();
        }
        cout << "\n>> Job deleted" << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << " Queue is empty!" << endl;
            return;
        }
        temp = head;
        while (temp != NULL)
        {
            temp->print();
            temp = temp->getNext();
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue<int> PQ;

    int ch, id, priority, data;
    while(true)
    {
        cout << endl << "======== MENU ========\n1.Insert job\n2.Delete job\n3.Display Jobs\n4.Exit\n======================\n\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter Job ID : ";
            cin >> id;
            cin.ignore();
            cout << "\nEnter Job Data : ";
            cin >> data;
            cin.ignore();
            cout << "\nEnter Job Priority : ";
            cin >> priority;
            cin.ignore();
            PQ.enqueue(id, data, priority);
            break;
        case 2:
            PQ.dequeue();
            break;
        case 3:
            cout << "\n>> Jobs in queue:  \n";
            PQ.display();
            break;
        case 4:
            cout << "\nExit";
            break;
        default:
            cout << "\n>> Invalid choice!";
            exit(0);
            break;
        }
    }
    return 0;
}
