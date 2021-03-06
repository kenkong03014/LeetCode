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

bool isValid(string s) {
    if(s.size() == 0 || s.size()%2 != 0 )
        return false;
    else if(s[0] == ')' || s[0] == ']' || s[0] == '}')
        return false;
    
    int* charArr = new int[6];
    int* arrPos = new int[3];
    vector<int> trackOpen;
    int count = 0;
    int tmp =0;

    for(int i =0; i<6; i++)
    {
        charArr[i] = 0;
        
        if(i<3)
            arrPos[i] = 0;
    }

    for(int i =0; i<s.size(); i++)
    {
        if(s[i] == '(')
        {
            charArr[0]++;
            arrPos[0] = i;
            trackOpen.push_back(1);
        }
        else if(s[i] == ')')
        {
            tmp = charArr[1] + 1;
            if(tmp > charArr[0])
                return false;
            else
            {
                charArr[1]++;
                if(arrPos[0]%2 == i%2  || trackOpen.back() != 1 )
                {
                    cout << "bakc is: " << trackOpen.back() << endl;
                    cout << i << ": here\n";
                    return false;
                }
                trackOpen.pop_back();
            }
        }
        else if(s[i] == '[')
        {
            charArr[2]++;
            arrPos[1] = i;
            trackOpen.push_back(2);
        }
        else if(s[i] == ']')
        {
            tmp = charArr[3] + 1;
            if(tmp > charArr[2])
                return false;
            else
            {
                charArr[3]++;
                if(arrPos[1]%2 == i%2 || trackOpen.back() !=2 )
                {
                    cout << i << ": here2\n";
                    return false;
                }
                trackOpen.pop_back();
            }
        }
        else if(s[i] == '{')
        {
            charArr[4]++;
            arrPos[2] = i;
            trackOpen.push_back(3);
        }
        else if(s[i] == '}')
        {
            tmp = charArr[5] + 1;
            if(tmp > charArr[4])
                return false;
            else
            {
                charArr[5]++;
                if(arrPos[2]%2 == i%2 || trackOpen.back() !=3 )
                {
                    cout << "here3\n";
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