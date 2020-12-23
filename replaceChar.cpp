#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
using namespace std;

string replaceChar(string s1)
{
    if(s1.size() == 0 || s1.size() == 1)
        return s1;
    
    int count = 0;

    for(int i =0; i<s1.size();i++)
    {
        if(s1[i] == ' ')
            count++;
    }

    if(count == 0)
        return s1;
    
    int newSize = s1.size() - count + count*3;
    char* newString = new char[newSize];

    int j = 0;
    for(int i =0; i<s1.size();i++)
    {
        if(s1[i] == ' ')
        {
            newString[j] = '%';
            newString[j+1] = '2';
            newString[j+2] = '0';
            j = j+3;
        }
        else
        {
            newString[j] = s1[i];
            j++;
        }
            
    }
    newString[newSize] = '\0';

    return newString;

}

int main()
{
    string input = "Mr 3ohn Smith";
    string input2 = replaceChar(input);


    cout << "input2 is:" << input2 << endl;
    return 0;
}