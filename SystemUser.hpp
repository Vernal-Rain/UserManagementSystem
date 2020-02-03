//SystemUser class
//Elaine Lee
//Dec 2019 for Csci 1113

#ifndef SU_HPP
#define SU_HPP
#include <iostream>
#include <fstream>
using namespace std;

class SystemUser
{
	public:
	SystemUser(); //Constructs SystemUser with username and password of "empty"
	SystemUser(string, string); //Constructs SystemUser with given username and password
	
	string getUsername() const; 
	void setUsername(string);
	
	bool checkPassword(string) const;
	bool updatePassword(string p1, string p2); //Updates password to p2 if p1 matches current password
	
	bool operator ==(SystemUser) const; //Checks whether two USERNAMES are identical
	bool operator !=(SystemUser) const; //Checks whether two USERNAMES are different
	
	friend istream& operator >>(istream&, SystemUser&);
	friend ostream& operator <<(ostream&, SystemUser&); //Outputs "<username> <password>"

	private:
	string username, password;
};

#endif
