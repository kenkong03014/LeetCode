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
/** n^2
string compressString(string input)
{
    if(input.size() < 3)
        return input;
    
    char* output = new char[input.size()-1];

    output[0] = input[0];
    int outputPos = 0;
    int charCount = 1;
    char* buffer;
    int loopCount = 0;
    for(int i =1; i<= input.size(); i++)
    {
        if(outputPos == input.size() - 1)
            return input;
        if(input[i] == output[outputPos])
        {
            charCount++;
            continue;
        }
        else
        {
            if(charCount <= 9)
            {
                buffer = new char[1];
                loopCount = 1;
            }
            else if(charCount <= 99)
            {
                buffer = new char[2];
                loopCount = 2;
            }
            else if(charCount <= 999)
            {
                buffer = new char[3];
                loopCount = 3;
            }
            
            itoa(charCount, buffer, 10);
            for(int i =0; i< loopCount; i++)
            {
                outputPos++;
                output[outputPos] = buffer[i];
            }
            if(outputPos < input.size()-1)
            {
                outputPos++;
                output[outputPos] = input[i];
            }
            charCount = 1;
        }
    }

    output[outputPos] = '\0';

    return output;
}
*/

/* O(n) */
string compressString(string input)
{
    if(input.size() < 3)
        return input;
    
    char* output = new char[input.size()-1];
    int outputPos = 0;
    int charCount = 0;
    char* buffer;

    for(int i =0; i< input.size(); i++)
    {
        charCount++;
        buffer = new char[1];
        if(input[i+1] != input[i])
        {
            output[outputPos++] = input[i];
            itoa(charCount, buffer,10);
            output[outputPos++] = buffer[0];
            charCount = 0;
        }
    }

    output[outputPos] = '\0';

    return output;
}
int main()
{
    string input = "aabcccccAA";

    string output = compressString(input);

    cout << "output is: " << output << endl;
    return 0;
}