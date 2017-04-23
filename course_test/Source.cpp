#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

#include "TLongNumber.h"

using namespace std;

int main(int argc, char ** argv)
{
	ifstream in1(argv[1]);
	ifstream in2(argv[2]);

	TLongNumber a, b, c;
	in1 >> a;
	in2 >> b;

	using namespace std;
	clock_t begin = clock();

	c = a * b;

	clock_t end = clock();

	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time elapsed: "<<elapsed_secs <<" seconds"<< endl;
	

	ofstream out("output.txt");

	out << c.get_number() << endl;

	in1.close();
	in2.close();
	out.close();

	return 0;
}