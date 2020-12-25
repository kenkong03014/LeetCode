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

/** Main points:
 * 1. check equal size of '(', '{', and '['.
 * 2. Use vector to keep track the lastest open symbol.
 * For example, ([{}, '{' is the lastest open sysmbol, so we expect the next
 * close symbol would be '}', otherwise, return false.
 */
bool isValid(string s) {
    if(s.size() == 0 || s.size()%2 != 0 )
        return false;
    else if(s[0] == ')' || s[0] == ']' || s[0] == '}')
        return false;
    else if(s.size() == 2 && s[0] == s[1])
        return false;
    
    int* charArr = new int[6];
    vector<int> trackOpen;

    for(int i =0; i<6; i++)
    {
        charArr[i] = 0;
    }

    for(int i =0; i<s.size(); i++)
    {
        if(s[i] == '(')
        {
            charArr[0]++;
            trackOpen.push_back(1);
        }
        else if(s[i] == ')')
        {
            if(charArr[1] + 1 > charArr[0])
                return false;
            else
            {
                charArr[1]++;
                if(trackOpen.back() != 1 )
                {
                    return false;
                }
                trackOpen.pop_back();
            }
        }
        else if(s[i] == '[')
        {
            charArr[2]++;
            trackOpen.push_back(2);
        }
        else if(s[i] == ']')
        {
            if(charArr[3] + 1 > charArr[2])
                return false;
            else
            {
                charArr[3]++;
                if(trackOpen.back() !=2 )
                {
                    return false;
                }
                trackOpen.pop_back();
            }
        }
        else if(s[i] == '{')
        {
            charArr[4]++;
            trackOpen.push_back(3);
        }
        else if(s[i] == '}')
        {
            if(charArr[5] + 1 > charArr[4])
                return false;
            else
            {
                charArr[5]++;
                if(trackOpen.back() !=3 )
                {
                    return false;
                }
                trackOpen.pop_back();
            }
        }       
    }

    if(charArr[0] == charArr[1] && charArr[2] == charArr[3] && charArr[4] == charArr[5])
        return true;
    
    return false;
}

int main()
{
    string input = "(([]){})";
    int count = 1;
    cout << "string is: " << input[count] << endl;
    if(isValid(input) == false)
        cout << "False\n";
    else
        cout << "True\n";
    
    return 0;
}