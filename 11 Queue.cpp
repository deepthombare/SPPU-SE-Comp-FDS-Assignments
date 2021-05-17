//============================================================================
// Name        : Queue.cpp
// Author      : Deep Thombare
// Assignment  : 11
// Description : Hello World in C++, Ansi-style
/*
 * Queues are frequently used in computer programming, and a typical example is
 * the creation of a job queue by an operating system.
 * If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
 * Write C++ program for simulating job queue.
 * Write functions to add job and delete job from queue. */
//============================================================================

#include <iostream>
#include<string>
using namespace std;

struct QNode {
    string data;
    QNode* next;
    QNode(string d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue { // Add at rear and delete at front
    QNode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }

    void enQueue(string x)
    {
        QNode* temp = new QNode(x);

        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void deQueue()
    {
        if (front == NULL)
            return;

        QNode* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete (temp);
    }
};
int main() {
	Queue q;
	while(true){
			cout<<"\n--------------------------------------"
					"\nEnter your choice"
				"\n1.Add job"
				"\n2.Delete job"
				"\n3.Display jobs"
				"\n4.Exit.";
			int c;
			cin>>c;
			switch(c)
			{
			case 1:{string s;
			cin.ignore();
					cout<<"\nEnter job name ";
					getline(cin,s);
					q.enQueue(s);
					break;}
			case 2 :{q.deQueue();
			break;}
			case 3:{
				QNode *ptr;
				ptr = q.front;
				while(ptr!=NULL)
				{
					cout<<endl<<ptr->data;
					ptr = ptr->next;
				}

			}break;
			default : exit(0);
			}
	}
	return 0;
}
