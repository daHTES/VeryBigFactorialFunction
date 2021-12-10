#include <iostream>
#include "veryLong.h"

void veryLong::putvl() const 
{
    char temp[SZ];
    strcpy_s(temp, vlstr);
    std::cout << _strrev(temp);
}

void veryLong::getvl() 
{
    std::cin >> vlstr;
    len = strlen(vlstr);
    _strrev(vlstr);
}

veryLong veryLong::operator+(const veryLong v)
{
    char temp[SZ];
    int j;

    int maxLen = (len > v.len) ? len : v.len;
    int carry = 0;
    for (j = 0; j < maxLen; j++) 
    {
        int d1 = (j > len - 1) ? 0 : vlstr[j] - '0';
        int d2 = (j > v.len - 1) ? 0 : v.vlstr[j] - '0';
        int digitSum = d1 + d2 + carry;
        if (digitSum >= 10)
        {
            digitSum -= 10;
            carry = 1;
        }
        else
            carry = 0;
        temp[j] = digitSum + '0';
    }
    if (carry == 1)
        temp[j++] = '1';
    temp[j] = '\0';
    return veryLong(temp);
}

veryLong veryLong::operator*(const veryLong v) 
{
    veryLong pprod;
    veryLong tempSum;
    for (int j = 0; j < v.len; j++) 
    {
        int digit = v.vlstr[j] - '0';
        pprod = multiDigit(digit);
        for (int k = 0; k < j; k++)
            pprod = multi10(pprod);
        tempSum = tempSum + pprod;
    }
    return tempSum;
}

veryLong veryLong::multi10(const veryLong v) const 
{
    char temp[SZ];
    for (int j = v.len - 1; j >= 0; j--)
        temp[j + 1] = v.vlstr[j];
    temp[0] = '0';
    temp[v.len + 1] = '\0';
    return veryLong(temp);
}

veryLong veryLong::multiDigit(const int d2) const 
{
    char temp[SZ];
    int j, carry = 0;
    for (j = 0; j < len; j++) 
    {
        int d1 = vlstr[j] - '0';
        int digitProd = d1 * d2;
        digitProd += carry;
        if (digitProd >= 10)
        {
            carry = digitProd / 10;
            digitProd -= carry * 10;
        }
        else
            carry = 0;
        temp[j] = digitProd + '0';
    }
    if (carry != 0)
        temp[j++] = carry + '0';
    temp[j] = '\0';
    return veryLong(temp);
}


int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned long numb, j;
    veryLong fact = 1;

    cout << "\n\n Введите число: ";
    cin >> numb;

    for (j = numb; j > 0; j--)
        fact = fact * j;
    cout << "Факториал = ";
    fact.putvl();
    cout << endl;

 return 0;
}




