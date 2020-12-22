#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
using namespace std;

//Best Time to Buy and Sell Stock.
bool uniqueChar(string input)
{
    int *htable = new int[input.size()];
    int n = input.size();
    
    for(int i=0; i< input.size(); i++)
    {
        cout << "input[" << i << "]: " << (122-(int)tolower(input[i])+1)%n << endl;

        if(htable[(122-(int)tolower(input[i])+1)%n] >= 0)
            htable[(122-(int)tolower(input[i])+1)%n] = -1;
        else
            return false;
    }
    return true;
}
int main()
{
    string input = "Abcdefga";
    bool isUnique = uniqueChar(input);

    if(isUnique == true)
        cout << "Unique!\n";
    else
        cout << "Repeated\n";
    return 0;
}