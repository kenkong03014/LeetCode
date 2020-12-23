#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) {

    if(words.size() == 0 || words.size() == 1)
        return true;
    
    int leftSize = words.size()/2;
    int rightSize = words.size() - leftSize;
    vector<string> leftside(leftSize);
    vector<string> rightside(rightSize);

    int* orderArr = new int[26];
    for(int i =0; i<26; i++)
    {
        orderArr[(122-(int)order[i]+1)%26] = i;
    }

    for(int i =0; i<leftSize; i++)
    {
        leftside[i] = words[i];
    }

    int rightCount=0;
    for(int i = leftSize; i<words.size(); i++)
    {
        rightside[rightCount] = words[i];
        rightCount++;
    }

    bool leftCheck = isAlienSorted(leftside, order);
    bool rightCheck = isAlienSorted(rightside, order);

    if(leftCheck == false || rightCheck == false)
        return false;
    
    int maxLength = max(leftside[leftSize-1].size(), rightside[0].size());

    for(int i =0; i< maxLength; i++)
    {
        if(orderArr[(122-(int)(leftside[leftSize-1][i])+1)%26] < orderArr[(122-(int)(rightside[0][i])+1)%26])
        {
            delete[] orderArr;
            if((int)(rightside[0][i]) == 0)
                return false;
           
            return true;
        }
        else if(orderArr[(122-(int)(leftside[leftSize-1][i])+1)%26] == orderArr[(122-(int)(rightside[0][i])+1)%26])
        {
            continue;
        }
        else
        {
            delete[] orderArr;
            return false;
        }
    }

    delete[] orderArr;
    return true;
}

int main()
{
    vector<string> words = {"hello","leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";

    bool check = isAlienSorted(words, order);

    if(check == true)
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}