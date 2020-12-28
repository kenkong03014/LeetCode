#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
#include <cstring>
using namespace std;

string addStrings(string num1, string num2) {
    if(num1.size() == 0 && num2.size() == 0)
        return "0";
    else if(num1.size() == 0 && num2.size() == 1)
        return num2;
    else if(num1.size() == 1 && num2.size() == 0)
        return num1;
    
    int carry = 0;
    int x1 = num1.size() - 1;
    int x2 = num2.size() - 1;
    string res ="";
    int maxItera = max(num1.size(), num2.size());
    for(int i = 0; i < maxItera; i++)
    {
        if(x1 < 0)
        {
            res += (((int)num2[x2]%48 + carry)%10 + '0');
            carry = ((int)num2[x2]%48 + carry)/10;
        }
        else if(x2 < 0)
        {
            res += (((int)num1[x1]%48 + carry)%10 + '0');
            carry = ((int)num1[x1]%48 + carry)/10;
        }
        else if(x1 >=0 && x2 >= 0)
        {
            res += (((int)num1[x1]%48 + (int)num2[x2]%48 + carry)%10 + '0');
            carry = ((int)num1[x1]%48 + (int)num2[x2]%48 + carry)/10;
        }
        x1--;
        x2--;
    }

    if(carry !=0)
        res += (carry + '0');
    
    reverse(res.begin(), res.end());

    return res;
}
int main()
{
    string num1 = "9";
    string num2 = "28";

    string res = addStrings(num1, num2);
    cout << "final res is: " << res << endl;
    return 0;
}