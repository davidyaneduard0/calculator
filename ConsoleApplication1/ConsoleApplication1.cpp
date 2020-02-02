#include<iostream>
#include<locale>
using namespace std;
 
int inDecimal(unsigned long long num);
int inDecimal(unsigned long long num)
{
	int a;
	int b = 0;
	int result = 0;
	while (num != 0)
	{
		a = num % 10;
		num = num / 10;
		if (b == 0)
			b = 1;
		if (b != 0)
			a *= b;
		result += a;
		b *= 2;
	}
	return result;
}
int  main()
{
const int gl_SIZESHORTINBITS = 8*sizeof(signed short int);


setlocale(LC_ALL, "English");

	signed short int x;

	cout << "Enter x:";
	cin >> x;

	int numbit = 0;

	cout << "Enter bit number (starting from the smallest):";
	cin >> numbit;
	int bits[gl_SIZESHORTINBITS];

	if (x < 0)
	{
		bits[gl_SIZESHORTINBITS - 1] = 1;
	}
	for (int i = 0; i < gl_SIZESHORTINBITS - 1; i++)
	{
		if (x%2 == 0)
		{
			bits[i] = 0;
		} else
		{
			bits[i] = 1;
		}
		x = x/2;
	}
	for (int i = 0; i < gl_SIZESHORTINBITS - 1; i++)
	{
		if (bits[i] == 1)
		{
			bits[i] = 0;
		}
		else
		{
			bits[i] = 1;
		}
	}
       bool carrier = true;
	   for (int i = 0; i < gl_SIZESHORTINBITS - 1; i++)
	   {
		   if (bits[i] == 1)
		   {
			   bits[i] = 0;
		   }
		   else
		   {
			   bits[i] = 1;
		   }
  }
	for (int i = gl_SIZESHORTINBITS-1; i >= 0; --i)
	{
		cout << bits[i];
	}
	cout << endl;
	setlocale(LC_ALL, "English");
    unsigned long long num;
	cout << "Enter a binary number(1 and 0):";
	cin >> num;
	cout << "Your number: " << inDecimal(num) << endl;

	return 0;
}