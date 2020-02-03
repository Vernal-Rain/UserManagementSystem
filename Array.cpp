//Dynamic array definitions
//Elaine Lee
//Dec 2019 for Csci 1113

#include <iostream>
#include <fstream>
#include "Array.hpp"
#include "SystemUser.hpp"
using namespace std;

Array::Array()
{
	max = 10;
	l = 0;
	users = new SystemUser[max];
}

Array::Array(const Array& other)
{
	l = other.l;
	max = other.max;
	users = new SystemUser[max];
	for (int i = 0; i < l; i++)
	{
		users[i] = other.users[i];
	}
}

void Array::operator =(const Array& other)
{
	delete [] users;
	
	l = other.l;
	max = other.max;
	users = new SystemUser[max];
	for (int i = 0; i < l; i++)
	{
		users[i] = other.users[i];
	}
}

Array::~Array()
{
	delete [] users;
}
	
void Array::expand()
{
	max *= 2;
	SystemUser *temp = new SystemUser[max];
	for (int i = 0; i < l; i++)
	{
		temp[i] = users[i];
	}
	delete [] users;
	users = temp;
}

int Array::getCount()
{
	return l;
}

void Array::add(SystemUser user)
{
	if (l == max) {expand();}
	users[l] = user;
	l++;
}

int Array::find(string username)
{
	for (int i = 0; i < l; i++)
	{
		if (users[i].getUsername() == username) {return i;}
	}
	return -1;
}

SystemUser Array::get(int n)
{
	return users[n];
}

void Array::print(ostream& out)
{
	for (int i = 0; i < l; i++)
	{
		out << users[i] << endl;
	}
}
