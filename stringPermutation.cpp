#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
using namespace std;

/** bool checkPermutation(string s1, string s2)
{
    if(s1.size() != s2.size())
        return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i=0; i<s1.size(); i++)
    {
        if(s1[i] != s2[i])
            return false;
    }

    return true;
}
*/

bool checkPermutation(string s1, string s2)
{
    if(s1.size() != s2.size())
        return false;
    int* charArray = new int[128];

    for(int i=0; i<128;i++)
    {
        charArray[i] = 0;
    }
    
    for(int i =0; i< s1.size();i++)
    {
        charArray[(int)s1[i]]++;
    }

    for(int i =0; i<s2.size();i++)
    {
        charArray[(int)s2[i]]--;
        if(charArray[(int)s2[i]]<0)
        {
            delete[] charArray;
            return false;
        }
    }

    delete[] charArray;
    return true;
}
int main()
{
    string s1 = "Abcde";
    string s2 = "dbcaA";

    if(checkPermutation(s1,s2))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}