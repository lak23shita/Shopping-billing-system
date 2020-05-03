/*
         SHOP BILLING SYSTEM
    OOP MINI PROJECT
    

*/

//Header Files-
#include<iostream>
#include<fstream>
#include <stdlib.h> 
using namespace std;

class head //Creation of Head Class
{
	char Iname[50][50];

public:
	int totalitems;
	float Qty[3];
	float price[3];
	int gstprice[3];
	int tprice[3];
	void input(); //Input Function
	void output(); //Output Function
};
class gst:public head //INHERITANCE
{
	float gsts;
public:
	void gstcal();
	void outputs();
	
};

//******************************************************************
//	    INPUT FUNCTION
//******************************************************************

void head::input()
{
	
	cout<<"\nEnter number of items= ";
	cin>>totalitems;

	for(int i=0; i<totalitems; i++)
	{
		cout<<"\nEnter name of item "<<i+1<<": ";
		cin>>Iname[i];
		cout<<"Enter quantity: ";
		cin>>Qty[i];
		cout<<"Enter price of item "<<i+1<<": ";
		cin>>price[i];
		tprice[i]=Qty[i]*price[i];
	}
}

//******************************************************************
//	   OUTPUT FUNCTION
//******************************************************************



void head::output()
{
	int a;  

	ifstream infile("count.txt");
	infile>>a;

	ofstream outfile("count.txt");
	a+=1;   
	outfile<<a;
	outfile.close();

	{   
	 ofstream outfile;
	 outfile.open("bill.txt", ios::app);
	outfile<<endl<<"Bill No.: "<<a<<endl;
	outfile<<"------------------------------------------------------------------------"<<endl;
cout<<"\n";
	cout<<"Name of Item\tQuantity   Price  Total Price\n";
	for(int i=0;i<totalitems;i++)
	{
		outfile<<"Name: "<<Iname[i]<<" Qty: "<<Qty[i]<<" Price: "<<tprice[i]<<endl;
		cout<<Iname[i]<<"\t\t"<<Qty[i]<<"\t   "<<price[i]<<"\t   "<<tprice[i]<<'\n';
	}

	outfile<<"------------------------------------------------------------------------"<<endl;
	outfile.close();
	}
}


//******************************************************************
//	   GST CALCULATION
//******************************************************************

void gst::gstcal() //for loop for GST calculation
{
	input();
	for(int i=0;i<totalitems;i++)
	{
		if(price[i]<=100.00)
		{
			gstprice[i]=tprice[i]+(0.05*tprice[i]);//Calculation of GST
			/*If amount is less than 100,
	        GST Percentage is 5% of the Total Amount*/
		}
		else
		{
			gstprice[i]=tprice[i]+(0.18*tprice[i]);
			//If Amount is greater than Rs. 100, GST applied is 18%.
		}
	}
}
//******************************************************************
//	    GST OUTPUTS
//******************************************************************

void gst::outputs() //Function for Output of Calculated GST
{
	output();

	float cash=0,sum=0,qty=0,sumt=0;

	for(int i=0;i<totalitems;i++)
	{
	       sumt+=tprice[i];
		   sum+=gstprice[i];
		   qty+=Qty[i];
	}
	cout<<"\nTotal:";
	cout<<"\n------------------------------------------------------------------------------";
	cout<<"\n\tQuantity= "<<qty<<"\t\t Sum= "<<sumt<<"\tWith Gst:"<<sum;
	cout<<"\n------------------------------------------------------------------------------";

pay:

	cout<<"\n\n\t\t\t****PAYMENT SUMMARY****\n"; //Bill Amount Display
	cout<<"\n\t\t\tTotal cash given: ";
	cin>>cash;

	if(cash>=sum)
		cout<<"\n\t\t\tTotal cash repaid: "<<cash-sum<<'\n';
		
	else //Message displayed if Cash is short
	{	cout<<"\n\t\t\tCash given is less than total amount!!!";

	goto pay;//function goes back to PAY
	}
}


//******************************************************************
//	    PROTECTION PASSWORD
//******************************************************************

int passwords()
{

	char p1,p2,p3;

	cout<<"\n\n\n\n\n\n\t\t\tENTER THE PASSWORD: ";

	cin>>p1;
	cin>>p2;
	cin>>p3; //input of password characters
	

	if ((p1=='n'||p1=='N')&&(p2=='l'||p2=='L')&&(p3=='s'||p3=='S'))

		return 1;

	else
		return 0;
}
// END of Password.

//****************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
	gst obj;
	char opt, ch;
	int x=1; //Variable for Password
	ifstream fin;

	if(x!=passwords()) //checking condtion for Correct Password
	{
		
		
			cout<<"\nWrong password \n";
			exit(0); //exit code if password input is wrong
	}

	 do{
	cout<<"\n\n\t\t\t------------------------------";
	cout<<"\n\t\t\t    Shop Billing System"; //Display of title
	cout<<"\n\t\t\t------------------------------";
	 cout<<"\n\n\t\t\tSelect any option:";
	 cout<<"\n\t\t\t1.\tTo enter new entry\n\t\t\t2.\tTo view previous entries\n\t\t\t3.\tExit\n";
	 cout<<"\n\nEnter your option: ";
	 cin>>opt;
	 switch(opt) //switch case for Option selection
	 {
	 case'1':
		 obj.gstcal();  //Calculating GST

		 obj.outputs();
		 break;
	 case'2':

		 fin.open("bill.txt", ios::in); //Opening File
		 while(fin.get(ch))
		 {
			 cout<<ch;
		 }
		 fin.close(); //Closing File

		 break;
	 case'3':
		 exit(0);
	 default:
		 cout<<"Invalid choice!\n";
	 }

	 }while(opt!=3);
	
	return 0;
}

/*
OUTPUT:



*************CORRECT PASSWORD***********************

			ENTER THE PASSWORD: nls


			------------------------------
			    Shop Billing System
			------------------------------

			Select any option:
			1.	To enter new entry
			2.	To view previous entries
			3.	Exit


Enter your option: 1

Enter number of items= 3

Enter name of item 1: Chocolate
Enter quantity: 25
Enter price of item 1: 10

Enter name of item 2: Juice
Enter quantity: 5
Enter price of item 2: 15

Enter name of item 3: Book
Enter quantity: 1
Enter price of item 3: 1250

Name of Item	Quantity   Price  Total Price
Chocolate		25	   10	   250
Juice		5	   15	   75
Book		1	   1250	   1250

Total:
------------------------------------------------------------------------------
	Quantity= 31		 Sum= 1575	With Gst:1709
------------------------------------------------------------------------------

			****PAYMENT SUMMARY****

			Total cash given: 25 000

			Total cash repaid: 291


			------------------------------
			     Shop Billing System
			------------------------------

			Select any option:
			1.	To enter new entry
			2.	To view previous entries
			3.	Exit


Enter your option: 1

Enter number of items= 1

Enter name of item 1: Shoes
Enter quantity: 1
Enter price of item 1: 2500

Name of Item	Quantity   Price  Total Price
Shoes		1	   2500	   2500

Total:
------------------------------------------------------------------------------
	Quantity= 1		 Sum= 2500	With Gst:2750
------------------------------------------------------------------------------

			****PAYMENT SUMMARY****

			Total cash given: 52  3000

			Total cash repaid: 250


			------------------------------
			     Shop Billing System
			------------------------------

			Select any option:
			1.	To enter new entry
			2.	To view previous entries
			3.	Exit


Enter your option: 2

Bill No.: 1
------------------------------------------------------------------------
Name: Chocolate Qty: 25 Price: 250
Name: Juice Qty: 5 Price: 75
Name: Book Qty: 1 Price: 1250
------------------------------------------------------------------------

Bill No.: 2
------------------------------------------------------------------------
Name: Shoes Qty: 1 Price: 2500
------------------------------------------------------------------------


			------------------------------
			     Shop Billing System
			------------------------------

			Select any option:
			1.	To enter new entry
			2.	To view previous entries
			3.	Exit


Enter your option: 3

********************WRONG PASSWORD******************
  ENTER THE PASSWORD: hg                                                                                                           
                                                                                                                                                         
Wrong password                                                                                                                                           
                                                                                                                                                         
                                                                                                                                                         
...Program finished with exit code 0 
****************MONEY PAID IS LESS THAN BILL AMOUNT******************






			ENTER THE PASSWORD: nls


			------------------------------
			     Shop Billing System
			------------------------------

			Select any option:
			1.	To enter new entry
			2.	To view previous entries
			3.	Exit


Enter your option: 1

Enter number of items= 2

Enter name of item 1: Pen
Enter quantity: 20
Enter price of item 1: 5

Enter name of item 2: Notebook
Enter quantity: 2
Enter price of item 2: 350

Name of Item	Quantity   Price  Total Price
Pen		20	   5	   100
Notebook		2	   350	   700

Total:
------------------------------------------------------------------------------
	Quantity= 22		 Sum= 800	With Gst:873
------------------------------------------------------------------------------

			****PAYMENT SUMMARY****

			Total cash given: 200

			Cash given is less than total amount!!!

			****PAYMENT SUMMARY****

			Total cash given: 2000

			Total cash repaid: 1127
*/