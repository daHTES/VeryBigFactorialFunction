#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int SZ = 1000;

class veryLong 
{
private:
	char vlstr[SZ];
	int len;
	veryLong multiDigit(const int) const;
	veryLong multi10(const veryLong) const;
public:
	veryLong() : len(0)
	{
		vlstr[0] = '\0';
	}
	veryLong(const char s[SZ]) 
	{
		strcpy_s(vlstr, s);
		len = strlen(s);
	}
	veryLong(const unsigned long n) 
	{
		_ltoa_s(n, vlstr, 10);
		_strrev(vlstr);
		len = strlen(vlstr);
	}
	void putvl() const;
	void getvl();
	veryLong operator + (const veryLong);
	veryLong operator * (const veryLong);
};
