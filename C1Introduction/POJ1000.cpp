#include<iostream>
#include<string>
using namespace std;
int main(int argc, char* argv[])
{
	int a=0, b=0;
	long sum;
	try
	{
		a = stoi(argv[1]);
		b = stoi(argv[2]);
	}
	catch(...)
	{
		cerr << "wrong parameter types"<<endl;
		return 0;
	}
	if((a>=0)&&(a<=10)&&(b>=0)&&(b<=10))
	{
		sum = a+b;
		cout << "the output is:"<<sum<<endl;
	}
	else
		cout << "the input number is not in the acceptable range";
	return 0;
}
