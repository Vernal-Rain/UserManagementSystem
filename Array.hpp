//Dynamic array class to store SystemUsers
//Elaine Lee
//Dec 2019 for Csci 1113

#ifndef ARR_HPP
#define ARR_HPP
#include <iostream>
#include <fstream>
#include "SystemUser.hpp"
using namespace std;

class Array
{
	public:
	Array(); //Creates an array of 10 new SystemUsers
	Array(const Array&);
	void operator =(const Array&);
	~Array();
	
	int getCount(); //Returns number of users
	void expand(); //Increases max length of array 2x
	void add(SystemUser); 
	int find(string); //Searches for SystemUser by username
	SystemUser get(int);
	void print(ostream&);
	
	private:
	int max, l; //max = length of array, l = number of SystemUsers in array whose user & pass are NOT "empty"
	SystemUser *users; 
};

#endif
