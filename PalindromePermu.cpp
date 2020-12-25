#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
#include<cstring>
using namespace std;

bool isPalndromePermu(string s1)
{
    if(s1.size() == 0 || s1.size() == 1)
        return true;
    else if(s1.size()%2 != 0)
        return false;
    
    int* charArr = new int[128];

    for(int i=0 ;i<128; i++)
    {
        charArr[i] = 0;
    }

    for(int i=0; i<s1.size(); i++)
    {
        if(s1[i] == ' ')
            continue;
        
        charArr[(int)s1[i]%128]++;
    }

    int count =0;

    for(int i=0; i<128; i++)
    {
        if(charArr[i] == 0 || charArr[i]%2 == 0)
            continue;
        
        count++;
        if(count > 1)
            return false;
    }

    return true;
}

int main()
{
    string input = "tact coa";

    if(isPalndromePermu(input))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}