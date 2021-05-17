//============================================================================
// Name        : Appointment scheduling.cpp
// Author      : Deep Thombare
// Assignment  : 8
// Description : Hello World in C++, Ansi-style
/*
 * Write C++ program for storing appointment schedule for day. Appointments are booked randomly using linked list.
 * Set start and end time and min and max duration for visit slot. Write functions for-
 * a) Display free slots b) Book appointment c) Cancel appointment ( check validity, time bounds, availability)
 * d) Sort list based on time e) Sort list based on time using pointer manipulation
 * */
#include<iostream>
using namespace std;

int size;	// No of Nodes or Appointments

struct SLL_Node	// Node Structure of each Appointment
{
    int start;
    int end;
    int flag;
    struct SLL_Node *next;
}*head;


class App_Shedule
{
  public:
	void create_Shed();

	void display_Shed();

	void book_App();

	void cancel_App();

	void sort_App();

}A1;


int main()
{
   int ch;
   while(true)
   {
      cout<<"\n\n *** Menu ***";
      cout<<"\n 1. Create Appointment Schedule";
      cout<<"\n 2. Display Free Slots";
      cout<<"\n 3. Book an Appointment";
      cout<<"\n 4. Cancel an Appointment";
      cout<<"\n 5. Sort slots based on Time";
      cout<<"\n 6. Exit";

      cout<<"\n Enter your choice: ";
      cin>>ch;

      switch(ch)
      {
         case 1: A1.create_Shed();
         	 break;

         case 2: A1.display_Shed();
         	 break;

         case 3: A1.book_App();
         	 break;

         case 4: A1.cancel_App();
         	 break;

         case 5: A1.sort_App();
         	 break;

         default: exit(0);

      }
   }

}


void App_Shedule :: create_Shed()           //Function Definition to create Appointment Schedule
{
    int i;
    struct SLL_Node *temp, *last;

    head = NULL;

    cout<<"\n How many Appointment Slots: ";
    cin>>size;

    for(i=0; i<size; i++)
    {
       temp = new struct SLL_Node;         // Step 1: Dynamic Memory Allocation

       cout<<"\n Enter Start Time: ";   // Step 2: Assign time
       cin>>temp->start;
       cout<<"\n Enter End Time: ";
       cin>>temp->end;
       temp->flag = 0;
       temp->next = NULL;

       if(head == NULL)
       {
          head = temp;
          last = head;
       }
       else
       {
          last->next = temp;
          last = last->next;
       }

    }
}


void App_Shedule :: display_Shed()          //Function Definition to Display Appointment Schedule
{
   int cnt = 1;
   struct SLL_Node *temp;

   cout<<"\n ****Appointment Schdule****";
   cout<<"\n Srno.\tStart\tEnd\tStatus";

   temp = head;
   while(temp != NULL)
   {
      cout<<"\n "<<cnt;
      cout<<"\t "<<temp->start;
      cout<<"\t "<<temp->end;


      if(temp->flag)
         cout<<"\t-Booked-";
      else
         cout<<"\t--Free--";

      temp = temp->next;
      cnt++;
   }
}


void App_Shedule :: book_App()              //Function Definition to Book Appointment
{
    int start;
    struct SLL_Node *temp;

    cout<<"\n Please enter Appointment time: ";
    cin>>start;

   temp = head;

   while(temp != NULL)
   {
      if(start == temp->start)
      {
         if(temp->flag == 0)
         {
            cout<<"\n Appointment Slot is Booked!!!";
            temp->flag = 1;
         }
         else
            cout<<"\n Appointment Slot is not Available!!!";
      }

      temp = temp->next;
   }

}



void App_Shedule :: cancel_App()            //Function Defination to Cancel Appointment
{
    int start;
    struct SLL_Node *temp;

    cout<<"\n Please enter Appointment time to Cancel: ";
    cin>>start;

   temp = head;

   while(temp != NULL)
   {
      if(start == temp->start)
      {
         if(temp->flag == 1)
         {
            cout<<"\n Your Appointment Slot is Canceled!!!";
            temp->flag = 0;
         }
         else
            cout<<"\n Your Appointment was not Booked!!!";
      }

      temp = temp->next;
   }
}


void App_Shedule :: sort_App()              //Function Definition to Sort Appointments
{
   int i,val;
   struct SLL_Node *temp;


   for(i=0; i < size-1; i++)
   {
       temp = head;
       while(temp->next != NULL)
       {
          if(temp->start > temp->next->start)
          {
              val = temp->start;
	      temp->start = temp->next->start;
	      temp->next->start = val;

              val = temp->end;
	      temp->end = temp->next->end;
	      temp->next->end = val;

	      val = temp->flag;
			  temp->flag = temp->next->flag;
			  temp->next->flag = val;

          }
          temp = temp->next;
       }
   }

   cout<<"\n The Appointments got Sorted!!!";

}
