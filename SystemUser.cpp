//SystemUser definitions
//Elaine Lee
//Dec 2019 for Csci 1113

#include <iostream>
#include <fstream>
#include "SystemUser.hpp"
using namespace std;

SystemUser::SystemUser()
{
	username = "empty";
	password = "empty";
}
SystemUser::SystemUser(string u, string p)
{
	username = u;
	password = p;
}

string SystemUser::getUsername() const
{
	return username;
}
void SystemUser::setUsername(string u)
{
	username = u;
}
	
bool SystemUser::checkPassword(string p)const
{
	return p == password;
}
bool SystemUser::updatePassword(string p1, string p2)
{
	if (p1 == password) {password = p2; return true;}
	return false;
}
	
bool SystemUser::operator ==(SystemUser su) const
{
	return username == su.username;
}
bool SystemUser::operator !=(SystemUser su) const
{
	return username != su.username;
}

istream& operator >>(istream& in, SystemUser& su)
{
	in >> su.username >> su.password;
	return in;
}
ostream& operator <<(ostream& out, SystemUser& su)
{
	out << su.username << " " << su.password;
	return out;
}
