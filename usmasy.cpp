//User management system - contains main function
//Elaine Lee
//Dec 2019 for Csci 1113

#include <iostream>
#include <fstream>
#include "SystemUser.hpp"
#include "Array.hpp"
using namespace std;

void help(); 
string load(Array &u); //Reads users from file
void save(Array &u); //Saves users to file
void stat(Array &u); //Displays current users in system
string login(Array &u); 
string addUser(Array &u);
void exit(); 

int main()
{
	string c;
	cout << "Welcome to USMASY the user management system \nenter command: "; 
	cin >> c;
	
	Array user_list;
	
	while (c != "exit")
	{
		if (c == "help") {help();}
		else if (c == "load") {cout << load(user_list);}
		else if (c == "save") {save(user_list);}
		else if (c = "stat") {stat(user_list);}
		else if (c == "login") {cout << login(user_list);}
		else if (c == "addUser") {cout << addUser(user_list);}
		else {cout << "ERROR: unknown command: " << c << " type help for a command list\n";}
		
		cout << "enter command: "; cin >> c;	
	}
	
	exit();
	
	return 0;
}

void help()
{
	cout << "The USMASY commands are:\n"
	<< "* help \n* load \n* login \n* addUser \n* save \n* exit\n";
}

string load(Array &u)
{
	if (u.getCount() > 0) {return "ERROR: user data already loaded.\n";}
	string f;
	cout << "enter a USMASY file name: "; cin >> f;
	ifstream in;
	in.open(f);
	if (!in.good()) {return ("unable to open " + f + "\n");}
	
	SystemUser temp;
	while (in >> temp)
	{
		u.add(temp);
	}
	in.close();
	
	return "";
}

void save(Array &u)
{
	string f;
	cout << "enter a USMASY file name: "; cin >> f;
	ofstream out;
	out.open(f);
	
	u.print(out);
	out.close();
}

void stat(Array& u)
{
	char disp;
	cout << "current users: " << u.getCount()
		<< "\n see all users? (y/n) ";
	cin >> disp;
	if (disp) 
	{
		for (int i = 0; i < u.getCount(); i++)
		{
			cout << u[i].getUsername() << endl;
		}
	}

}

string login(Array &u)
{
	string user, pass;
	cout << "username: "; cin >> user;
	
	if (u.find(user) == -1) {return "ERROR: unable to find user data\n";}
	else 
	{
		int tries = 0;
		while (tries < 3)
		{
			cout << "password: "; cin >> pass;
			if (u.get(u.find(user)).checkPassword(pass)) 
			{return "login successful\n";}
			else {cout << "ERROR: incorrect password\n"; tries ++;}
		}
		return "ERROR: login failed after 3 incorrect attempts\n";
	}
}

string addUser(Array &u)
{
	SystemUser user;
	cout << "username and password: "; cin >> user;
	
	if (u.find(user.getUsername()) != -1) 
	{return "ERROR: username in use\n";}

	u.add(user);
	return "";
}

void exit()
{
	cout << "Goodbye!\n";
}
