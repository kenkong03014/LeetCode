#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
using namespace std;

vector<string> fizzBuzz(int n) {
        vector<string> res;

        for(int i =1; i <=n; i++)
        {
            if(i%3 == 0 && i%5 == 0)
                res.push_back("FizzBuzz");
            else if(i%3 == 0)
                res.push_back("Fizz");
            else if(i%5 == 0)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }

        return res;
}
int main()
{
    vector<string> input = fizzBuzz(15);

    for(int i = 0; i< (int)input.size(); i++)
    {
        cout << input[i] << endl;
    }


    return 0;
}