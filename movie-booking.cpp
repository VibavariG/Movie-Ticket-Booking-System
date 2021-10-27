/*
Roll numbers 
2345 Manasi Kasande
2337 Sejal Jagtap 
2325 Vibavari G
2342 Kanchan Chib */
#include <iostream>
using namespace std;
class seat
{
	int seatNum;
	bool booked;
	float price;
	char row;
	friend class theatre;

	public:

		seat()
		{
			//initially all seats are unbooked
			//false - unbooked and true - booked
			booked = false;
			price = 0.0f;

		}

};
class theatre
{
	seat s[10][20];
	

	public:
	theatre()
	{
		char c = 'A';
		for (int i = 0; i < 10; i++,c++)
		{
			//inistialising details of each seat
			//Rows - A to J
			//seat number - 1 to 20
			//Rows A,B,C: Recliner
			//Rows D,E,F,G: Gold
			//Rows H,I,J: Silver

			for (int j = 0,n = 1;  j < 20; j++,n++)
			{
				s[i][j].row = c;
				s[i][j].seatNum = n;
				if(i < 3)
				{
					//recliner
					s[i][j].price = 150.0;
				}
				else if((i > 3)&&(i < 8))
				{
					//gold
					s[i][j].price = 120.0;
				}
				else
				{
					//silver
					s[i][j].price = 80.0;
				}
			}
		}
	}

	void display();

	void bookTickets();

	void cancelBooking();


};
void theatre::bookTickets( )
{
	cout<<"\n\tBefore Booking:\n\n";	
	 display();
     int flag=0;
     char r,ch;
     int row,co,no;
     int f=0;
    
     do
	{
		//validation for number of tickets
    	cout<<"\n\tEnter the number of tickets: ";
    	cin>>no;
    	if(no < 0)
    	{
    		cout<<"\n\tInvalid input\n";
    	}
    	else if(no > 20)
    	{
    		cout<<"\n\tOnly 20 seats are available\n";
    	}
     }while(no < 0||no > 20);

     do
     {
    	 f = 0;
    	 flag = 0;

    	 do
    	 {
    		 cout<<"\n\tEnter row: ";
    		 cin>>r;
    		 if(!(r > 64&&r <= 74))
    		 {
    			 cout<<"\n\tRow are from 'A' to 'J'\n\tPlease enter valid row\n";
    		 }
    	 }while(!((r > 64)&&(r <= 74)));
    	 //till row is not lying between A and J

    	 cout<<"\n\tEnter seat number : ";
    	 cin>>co;

     	for(int i=co-1;i<(no+co-1);i++)
         {
        	if((s[r - 'A'][i].booked == false) &&(i < 20))
        	{
        		flag++;
        	}
         }

	     if(flag == no)
	     {
	     	//actual booking happens here
	     	cout<<"\n\tNumber of tickets: "<<no;
	    	cout<<"\n\tTotal Price: "<<s[row][co-1].price*no<<endl;
	    	cout<<"Do u want to confirm(Y/N): ";
	    	cin>>ch;

	    	 if(ch=='Y'||ch=='y')
	    	 {
	    	 	//user says yes while confirmation
	    		 for(int i=co-1;i<(no+co-1);i++)
	    		     {
	    		     	//indicates that ticket is booked
	    		    	s[r - 'A'][i].booked =true;
	    		     }
	    		 cout<<"Ticket is booked\n";
	    		 cout<<"\n\tAfter Booking: \n";
	    		 display();

	    	 }
	    	 else
	    	 {
	    	 	//user says no while confirmation
	    	 	cout<<"\n\tCould not complete your request\n";
	    	 }
	     }
	     else
	     {
	     	//validation - seat number not available
	    	 cout<<"NOT AVAILABLE!!\n";
	    	 cout<<"Choose another seat number\n";
	    	 f=1;
	     }

     }while(f==1);
}
void theatre::cancelBooking()
{
	int flag=0;
	int seatNum;
	char rownum;
	

	cout<<"\n\t Please enter the seat number";
	cin>>seatNum;
	cout<<"\n\tPlease enter row number";
	cin>>rownum;

	if((seatNum > 0)&&(seatNum < 21)&&(rownum >= 'A')&&(rownum <= 'J'))
	{
		if(s[rownum -'A'][seatNum-1].booked == true)
		{
			//changing status from booked to unbooked
			s[rownum -'A'][seatNum-1].booked=false;
			cout<<"\n\tCancellation successful\n";	
		}
		else
		{
			//validation - entered seat is not booked
			cout<<"\n\tCannot cancel a seat which is not booked\n";
		}	
		
	}
	else
	{
		//validation - seat does not exist 
		cout<<("\n\tSorry reservation number not valid hence cancellation not possible");
	}




}


void theatre::display()
{
	cout<<"\n\n\n\n";
	cout<<"\n\tU : Unbooked";
	cout<<"\n\tB : Booked\n\n\n";
	int j,i;
	cout<<"\t";
	for(int i=1;i<=20;i++)					//column numbers
	{
		if(i==6||i==16)
		{
			cout<<"\t";
		}
		cout<<" "<<i<<"\t";
	}
	cout<<"\n";
	//cout<<"\n";

	cout<<"Recliner(Price: Rs.150)\n\n";

	for(i=0;i<10;i++)
	{
		if(i==3||i==7)						//gives space between silver, gold and recliner
		{
			cout<<"\n\n";
			//cout<<"\n";
			if(i==3)
			{
				cout<<"Gold(Price: Rs.120)\n\n";
			}
			else
			{
				cout<<"Silver(Price: Rs.80)\n\n";
			}
		}

		switch(i)							//switch to display row alphabets
		{
		case 0:
			cout<<"A\t";
			break;
		case 1:
			cout<<"B\t";
			break;
		case 2:
			cout<<"C\t";
			break;
		case 3:
			cout<<"D\t";
			break;
		case 4:
			cout<<"E\t";
			break;
		case 5:
			cout<<"F\t";
			break;
		case 6:
			cout<<"G\t";
			break;
		case 7:
			cout<<"H\t";
			break;
		case 8:
			cout<<"I\t";
			break;
		case 9:
			cout<<"J\t";
			break;
		}


		for(j=0;j<20;j++)											//showing booked/unbooked for each row
		{
			if(j==5||j==15)
			{
				cout<<"\t";//cout<<"---\n\t";
			}
			if(s[i][j].booked == false)
			{
				cout<<"| U |"<<"\t";
			}
			else
			{
				cout<<"| B |"<<"\t";
			}
		}
		cout<<"\n";
		//cout<<"\n";
	}
	cout<<"\n\n\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tSCREEN ";
	cout<<"\n______________________________________________________________________________________________";
	cout<<"_______________________________________________________________________________________________________";
	cout<<"\n\n\n\n";
}
int main(int argc, char const *argv[])
{

	theatre t[5];
	int ch, ch1;
	do
	{
		cout<<"\n\t\t\t\t\t\tWELCOME TO PVR CINEMAS ";
		cout<<"\n\tNow Showing: ";
		cout<<"\n\t1. Bala\n";
		cout<<"\n\t2. Yeh Jawani Hai Deewani\n";
		cout<<"\n\t3. 3 Idiots\n";
		cout<<"\n\t4. Zindagi Na Milegi Dobara\n";
		cout<<"\n\t5. War\n";
		cout<<"\n\t6. Exit\n";
		cout<<"\nEnter choice: \n";
		cin>>ch;

		if(ch==1||ch==2||ch==3||ch==4||ch==5)
		{
			cout<<"\n\tWhat do you want to do ?\n";
			cout<<"\n\t1. Book Tickets\n";
			cout<<"\n\t2. Cancel Tickets\n";
			cout<<"\n\t3. Display booking status\n";
			cout<<"\nEnter your choice: \n";
			cin>>ch1;

			switch(ch1)
			{
				case 1:
				t[ch].bookTickets();
				break;

				case 2:
				t[ch].cancelBooking();
				break;

				case 3:
				t[ch].display();
				break;

				default:
				cout<<"\n\tPlease enter correct choice\n";
			}
		}
		else if(ch==6)
		{
			
		}
		else
		{
			cout<<"Wrong Input";
		}

	}while(ch!=6);


	return 0;
}
/*
						WELCOME TO PVR CINEMAS 
	Now Showing: 
	1. Bala

	2. Yeh Jawani Hai Deewani

	3. 3 Idiots

	4. Zindagi Na Milegi Dobara

	5. War

	6. Exit

Enter choice: 
1 

	What do you want to do ?

	1. Book Tickets

	2. Cancel Tickets

	3. Display booking status

Enter your choice: 
1

	Before Booking:






	U : Unbooked
	B : Booked


	 1	 2	 3	 4	 5		 6	 7	 8	 9	 10	 11	 12	 13	 14	 15		 16	 17	 18	 19	 20	
Recliner(Price: Rs.150)

A	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
B	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
C	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	


Gold(Price: Rs.120)

D	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
E	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
F	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
G	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	


Silver(Price: Rs.80)

H	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
I	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
J	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	




											SCREEN 
_____________________________________________________________________________________________________________________________________________________________________________________________________




	Enter the number of tickets: 4

	Enter row: A

	Enter seat number : 2

	Number of tickets: 4
	Total Price: 600
Do u want to confirm(Y/N): Y
Ticket is booked

	After Booking: 





	U : Unbooked
	B : Booked


	 1	 2	 3	 4	 5		 6	 7	 8	 9	 10	 11	 12	 13	 14	 15		 16	 17	 18	 19	 20	
Recliner(Price: Rs.150)

A	| U |	| B |	| B |	| B |	| B |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
B	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
C	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	


Gold(Price: Rs.120)

D	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
E	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
F	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
G	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	


Silver(Price: Rs.80)

H	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
I	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
J	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	




											SCREEN 
_____________________________________________________________________________________________________________________________________________________________________________________________________




						WELCOME TO PVR CINEMAS 
	Now Showing: 
	1. Bala

	2. Yeh Jawani Hai Deewani

	3. 3 Idiots

	4. Zindagi Na Milegi Dobara

	5. War

	6. Exit

Enter choice: 
1

	What do you want to do ?

	1. Book Tickets

	2. Cancel Tickets

	3. Display booking status

Enter your choice: 
2

	 Please enter the seat number3

	Please enter row numberA

	Cancellation successful

						WELCOME TO PVR CINEMAS 
	Now Showing: 
	1. Bala

	2. Yeh Jawani Hai Deewani

	3. 3 Idiots

	4. Zindagi Na Milegi Dobara

	5. War

	6. Exit

Enter choice: 
1

	What do you want to do ?

	1. Book Tickets

	2. Cancel Tickets

	3. Display booking status

Enter your choice: 
3





	U : Unbooked
	B : Booked


	 1	 2	 3	 4	 5		 6	 7	 8	 9	 10	 11	 12	 13	 14	 15		 16	 17	 18	 19	 20	
Recliner(Price: Rs.150)

A	| U |	| B |	| U |	| B |	| B |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
B	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
C	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	


Gold(Price: Rs.120)

D	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
E	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
F	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
G	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	


Silver(Price: Rs.80)

H	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
I	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	
J	| U |	| U |	| U |	| U |	| U |		| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |	| U |		| U || U |	| U |	| U |	| U |	




											SCREEN 
_____________________________________________________________________________________________________________________________________________________________________________________________________




						WELCOME TO PVR CINEMAS 
	Now Showing: 
	1. Bala

	2. Yeh Jawani Hai Deewani

	3. 3 Idiots

	4. Zindagi Na Milegi Dobara

	5. War

	6. Exit

Enter choice: 
6
*/


