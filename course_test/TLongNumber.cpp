#include "TLongNumber.h"



TLongNumber::TLongNumber()
{
	number = "";
}

TLongNumber::TLongNumber(string number)
{
	this->number = number;
}

TLongNumber::TLongNumber(TLongNumber & obj)
{
	this->number = obj.number;
}

TLongNumber & TLongNumber::operator+(TLongNumber & b)
{
	string bigger, smaller, str_result = "";
	bool condition;

	if (this->number.size() > b.number.size()) condition = true;
	else if (this->number.size() < b.number.size()) condition = false;
	else condition = this->number > b.number;

	bigger = (condition	? this->number : b.number);
	smaller = (condition ? b.number: this->number);

	string::reverse_iterator big_iter = bigger.rbegin();
	string::reverse_iterator small_iter = smaller.rbegin();
	short addNum = 0, num1, num2, sum;
	while (big_iter != bigger.rend())
	{
		num1 = (int)(*(big_iter++)) - 48;
		if (small_iter == smaller.rend()) 
			num2 = 0;
		else num2 = (int)(*(small_iter++)) - 48;
		sum = num1 + num2 + addNum;
		str_result.insert(str_result.begin(), (char)(sum % 10 + 48));
		addNum = sum / 10;
	}
	if(addNum != 0)
		str_result.insert(str_result.begin(), (char)(addNum + 48));
	this->number = str_result;
	return *this;
}

TLongNumber & TLongNumber::operator*(TLongNumber & b)
{
	string bigger, smaller, result = "";
	bool condition;

	if (this->number.size() > b.number.size()) condition = true;
	else if (this->number.size() < b.number.size()) condition = false;
	else condition = this->number > b.number;

	bigger = (condition ? this->number : b.number);
	smaller = (condition ? b.number : this->number);

	this->number = "0";

	string::reverse_iterator small_iter = smaller.rbegin();
	string::reverse_iterator big_iter;

 	long long int index = 0;
	short addNum = 0, res, num1, num2;
	string inter_res_str;
	while (small_iter != smaller.rend())
	{
		inter_res_str = "";
		big_iter = bigger.rbegin();
		num1 = (int)(*(small_iter++)) - 48;
		addNum = 0;
		while (big_iter != bigger.rend())
		{
			num2 = (int)(*(big_iter++)) - 48;
			res = num1 * num2 + addNum;
			inter_res_str.insert(inter_res_str.begin(), (char)(res % 10 + 48));
			addNum = res / 10;
		}
		if(addNum != 0)
			inter_res_str.insert(inter_res_str.begin(), (char)(addNum + 48));
		for (long long int i = 0; i < index; i++)
			inter_res_str.push_back('0');
		
		TLongNumber inter_res(inter_res_str);

		*this = *this + inter_res;

		index++;
	}

	return *this;
}

TLongNumber & TLongNumber::operator=(TLongNumber & b)
{
	this->number = b.number;
	return *this;
}

string TLongNumber::get_number()
{
	return number;
}


TLongNumber::~TLongNumber()
{
}

istream & operator>>(istream & in, TLongNumber & obj)
{
	in >> obj.number;
	return in;
}
