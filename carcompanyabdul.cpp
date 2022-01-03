//Abdul-Samad Olagunju
//Ms. Dalal
//Computer Programming 
//Car Company Assignment
//May 19, 2017

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Windshieldrep
{
	//declare variables, create function
	public:
		float smallcrack = 100;
		float bigcrack = 150;
		float numofrepairs, total;
		float summerbill()	
		{
			//ask user for number of repairs, then get total bill
			cout << "How many small crack repairs would you like to do on your car? ";
			cin >> numofrepairs;
			smallcrack *= numofrepairs;
			cout << "How many big crack repairs would you like to do on your car? ";
			cin >> numofrepairs;
			bigcrack *= numofrepairs;	
			total = bigcrack + smallcrack;
		}
};
class Carwash
{
	//declare variable, create function
	public:
		float inwash = 80;
		float inoutwash = 200;
		float numofwashes, total;
		float winterbill()
		{
			//get number of washes, get total cost
			cout << "How many inner washes would you like to do on your car? ";
			cin >> numofwashes;
			inwash *= numofwashes;
			cout << "How many inner and outer washes would you like to do on your car? ";
			cin >> numofwashes;
			inoutwash *= numofwashes;	
			total = inwash + inoutwash;
		}
};
class UserInfo
{
	//get user info
	public:
		char surname[50];
		int age;
		void getInfo()
		{
			cout << "Please enter your surname: ";
			cin >> surname;
			cout << "Please enter your age: ";
			cin >> age;
		}
};

//declare discount function
float discount(char, float);

int main()
{
	//declare variables
	int count = 0;
	char check[50];
	char ans;
	float total = 0;
	char id[3];
	
	//open file to read and write
	ofstream write("carcompanyreceipt.txt", ios :: app);
	ifstream read("carcompanyreceipt.txt");
	cout << "Welcome to Olagunju's Car Wash! We offer you the best prices and the most customer satisfaction!" << endl;
	
	//run program until no more customers need to input information
	do
	{
		//get id from user
		count = 0;
		cout << "Please enter the first digit of your id: ";
		cin >> id[0];
		cout << "Please enter the second digit of your id: ";
		cin >> id[1];
		cout << "Please enter the third digit of your id: ";
		cin >> id[2];
		
		//check if id number is already in system
		while(!read.eof())
		{
			read >> check;
			if((check[0] == id[0]) && (check[1] == id[1]) && (check[2] == id[2]))
			{
				count++;
			}
		}
		
		//write id number, surname and age to file
		write << "ID Number: " << id << endl;
		UserInfo info;
		info.getInfo();
		write << "Surname: " << info.surname << endl;
		write << "Age: " << info.age << endl;
		
		//if counter adds 1, customer receives 20% discount
		if(count >= 1)
		{
			cout << "Our system tells us that you are a returning customer. You will receive a 20% discount on your final bill!" << endl;
		}
		else
		{
			cout << "Our system tells us that you are a new customer. Welcome!" << endl;
		}
		
		//show summer and winter deals
		cout << "We have exclusive summer and winter deals." << endl;
		cout << "If you select our summer deal, you can repair a small crack on your windshield for $100, or a big crack for $150." << endl;
		cout << "If you select our winter deal, you can have an inner wash done on your car for $80, or an inner and outer wash done for $200." << endl;
		
		//ask whether customer wants summer or winter deal
		do
		{
			cout << "Would you like to access our summer or winter deal? (s/w) ";
			cin >> ans;
		}while(ans != 's' && ans != 'w');
		
		//if customer wants summer deal
		if(ans == 's')
		{
			//create windshield object, if customer is returning, give 20% discount
			Windshieldrep obj;
			obj.summerbill();
			if(count >= 1)
			{
				ans = 'y';
			}
			else
			{
				ans = 'n';
			}
			total = obj.total;
			write << "Your total costs are: $" << discount(ans, total) << endl;
		}
		//if customer wants winter deal
		if(ans == 'w')
		{
			//create carwash object, if customer is returning, give 20% discount
			Carwash obj;
			obj.winterbill();
			if(count >= 1)
			{
				ans = 'y';
			}
			else
			{
				ans = 'n';
			}
			total = obj.total;
			write << "Your total costs are: $" << discount(ans, total) << endl;
			cout << "Your total costs are: $" << discount(ans, total) << endl;
		}
		write << "--------------------------------------" << endl;
		
		//ask if there is another customer, if there is, program will run again
		cout << "Is there another customer whose information needs to be inputted? (y/n) ";
		cin >> ans;
	}while(ans == 'y');	
	
	//give closing statement
	cout << "Thank you for visiting our business!" << endl;
	//close files7
	write.close();
	read.close();
}

//discount function, gives 20% discount
float discount(char ans, float bill)
{
	if(ans == 'y')
	{
		bill *= 0.8;
	}
	return bill;
}
