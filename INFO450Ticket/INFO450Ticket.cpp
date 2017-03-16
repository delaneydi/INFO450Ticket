// INFO450Ticket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Ticket
{
private:
	int ticketID; 
	string issueStatus;
	char issueType;
	string issuePriority;
	string userName;
	string issueDescription;
	int usersImpacted;
	static int IDgenerator;

public:
	Ticket()
	{
		ticketID = IDgenerator;
		IDgenerator++;
		issueStatus = "OPEN";
	}

	void CaptureTicket();
	void CloseTicket();
	void ShowTicket();

};
int Ticket::IDgenerator = 0;

void Ticket::CaptureTicket()
{
	cin.clear();
	cin.ignore();
	cout << "Please enter your first and last name" << endl;
	getline(cin, userName);
	cout << "Please enter the type of issue: S = Server, A = Application, C = Access" << endl;
	cin>>issueType;
	cin.ignore();
	cout << "Please provide a description of the issue" << endl;
	getline(cin, issueDescription);
	cout << "Please enter the number of users effected" << endl;
	cin >> usersImpacted;
	cin.clear();
	cin.ignore();   
	cout << "Your ticket ID is: " << ticketID << endl;

}

void Ticket::CloseTicket()
	{
		issueStatus = "CLOSE";    
	}
 

void Ticket::ShowTicket()
{

	cout << "TicketID: " << IDgenerator << "Type: ";
	switch(issueType)
	{
		case 'S':
		case 's':
			cout << "Type: Server" << endl;
			break;
		case 'A':
		case 'a' :
			cout << "Type: Application" << endl;
			break;
		case 'C':
		case 'c' :
			cout << "Type: Access" << endl;
			break;
		default:
			cout << "Invalid issue Type! Please try again" << endl;
			break;
	}
		cout << "Status: " << issueStatus << endl;
		cout << "Description:" << issueDescription << endl;
		cout << "User: " << userName << endl;
		cout << "Users Impacted: " << usersImpacted << endl;
		cout << "Ticket Priority: "; 
		if (usersImpacted < 10)
		{
			cout << " Priority = LOW" << endl;
		}

		if (usersImpacted >= 10 && usersImpacted < 50)
		{
			cout << " Priority = MED" << endl;
		}

		if (usersImpacted >= 50)
		{
			cout << " Priority = HIGH" << endl;
		}
		cout << "-----------------------------------" << endl;

}

int main()
{
		const int ticketMax = 100;
		char choice;
		Ticket myTicket[ticketMax];
		int ticketNumber = 0;
		do
		{
			cout << "Create new ticket? Press Y to continue." << endl;
			cin >> choice;
			switch (choice)
			{
			case 'Y':
			case 'y':
				myTicket[ticketNumber].CaptureTicket();
				++ticketNumber;
				break;
			default:
				cout << "Sorry try again" << endl;
				break;
			}
		}

		while (choice == 'Y' || choice == 'y');

		for (int i = 0; i < ticketNumber; ++i)
		{
			myTicket[i].ShowTicket();
		}

	return 0;
	}

