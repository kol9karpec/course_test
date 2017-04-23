#pragma once
#include <string>
#include <fstream>

using namespace std;

class TLongNumber
{
	string number;
public:
	TLongNumber();
	TLongNumber(string number);
	TLongNumber(TLongNumber & obj);

	TLongNumber & operator+(TLongNumber & b);
	TLongNumber & operator*(TLongNumber & b);
	TLongNumber & operator=(TLongNumber & b);
	friend istream & operator>>(istream & in, TLongNumber & obj);

	string get_number();

	~TLongNumber();
};

