//============================================================================
// Name        : Assignment.cpp
// Author      : Deep Thombare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/*The ticket booking system of Cinemax theater has to be implemented using C++ program.
 * There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows.
 * Assume some random booking to start with.
 * Use array to store pointers (Head pointer) to each row.
 * On demand
 * a) The list of available seats is to be displayed
 * b) The seats are to be booked
 * c) The booking can be cancelled. */
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class node
{
public : string status;
		node *next;
		node *prev;
		node ()
		{
			status = "NOT BOOKED";
			prev = NULL;
			next = NULL;
		}
};
int main() {
	node *ptr,*head[10],*current;
	for(int i = 0;i<10;i++)
	{
		ptr = new node;
		current = ptr;
		head[i] = ptr;

		for(int j = 1 ; j<=6 ; j++ )
		{
			ptr = new node;
			current->next = ptr;
			ptr->prev = current;
			current = ptr;
		}
		current->next = head[i];
		head[i]->prev = current;
	}
/*------------------------Menu--------------------------------------------*/

// prebooking
for(int i = 1;i<7;i++)
{
		node *p = head[i];

		for (int q = 0;q<i;q++)
		{
				p = p -> next;
		}
		p->status = "  BOOKED  ";
}
int c;
while (true)
{
	cout<<"\n\nChoose one "
			"\n1.Display status of all seats"
			"\n2.Book Seat"
			"\n3.Unbook Seat"
			"\n4.Exit";
	cin>>c;
	switch(c)
	{
	case 1: cout<<"\n	  COL1		 COL2		 COL3		 COL4		 COL5		 COL6		 COL7";
			for(int i = 0;i<=9;i++)
			{	cout<<"\nROW"<<i+1<<"	";
				node *p = head[i];
				for (int j = 0;j<=6 ;j++)
				{
						cout<<p->status<<"	";
						p = p->next;
				}
			}
		break;
	case 2 :{int r,c;
			cout<<"\nEnter ROW number";
			cin>>r;
			r--;
			cout<<"\nENter COLUMN number";
			cin>>c;
			c--;
			string s = "NOT BOOKED" ;

			if (r>=0 && r<10)
			{

				node *p = head[r];
				if(c>=0 && c<7)
				{
					for (int q = 0;q<c;q++)
					{
							p = p -> next;
					}
					if( p->status == s )
					{
						p->status = "  BOOKED  ";
						cout<<"\nYour seat is BOOKED";
					}
					else
					{
						cout<<"\nEnter Seat is booked please select another seat";
					}
				}
				else
				{
					cout<<"\nPlease enter valid column";
				}
			}
			else{
				cout<<"\nPlease enter valid row";
			}
		break;}
	case 3:{int r,c;
			cout<<"\nEnter ROW number";
			cin>>r;
			r--;
			cout<<"\nENter COLUMN number";
			cin>>c;
			c--;
			string s = "  BOOKED  " ;
			if (r>=0 && r<10)
			{	node *t = head[r];
				if(c>=0 && c<7)
				{
					for (int q = 0;q<c;q++)
					{
							t = t -> next;
					}
					if( t->status == s )
					{
						t->status = "NOT BOOKED";
						cout<<"\nSeat is UNBOOKED";
					}
					else
					{
						cout<<"\nEntered Seat is already unbooked ";
					}
				}
				else
				{
					cout<<"\nPlease enter valid column";
				}
			}
			else
			{
				cout<<"\nPlease enter valid row";
			}
			break;}
	default: {exit(0);}
	}

}
	delete[] ptr;
	return 0;
}
