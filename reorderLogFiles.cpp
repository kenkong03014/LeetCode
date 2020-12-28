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

/** vector<string> reorderLogFiles(vector<string>& logs) {
     if(logs.size() == 0 || logs.size() == 1)
        return logs;
    
    int* numArray = new int[logs.size()];

    vector<string> output;

    for(unsigned int i =0; i< logs.size(); i++)
    {
        numArray[i] = -1;
    }

    int numCount = 0;
    for(unsigned int i =0; i< logs.size(); i++)
    {
        for(unsigned int j = 0; j < logs[i].size(); j++)
        {
            if(logs[i][j] == ' ' && (int)logs[i][j+1]%123 >= 97)
            {
                output.push_back(logs[i]);
                break;
            }
            else if(logs[i][j] == ' ' && (int)logs[i][j+1]%58 < 58)
            {
                numArray[numCount++] = i;
                break;
            }
        }
    }

    for(int i = 0; i<numCount; i++)
    {
        output.push_back(logs[numArray[i]]);
    }

    delete[] numArray;
    return output;
} */

/** the comparator is mainly for comparing the string content by the order of
 * each character. If the content is the same, then we compare the identifier.
 */

/*
static bool comparator(string s1, string s2)
{
    int spacePos1 = s1.find(" ");
    string id1 = s1.substr(0, spacePos1);
    string content1 = s1.substr(spacePos1+1, s1.size());

    int spacePos2 = s2.find(" ");
    string id2 = s2.substr(0, spacePos2);
    string content2 = s2.substr(spacePos2+1, s2.size());

    if(isdigit(content1[0]) && !isdigit(content2[0]))
        return false;
    else if(!isdigit(content1[0]) && isdigit(content2[0]))
        return true;
    else if(!isdigit(content1[0]) && !isdigit(content2[0]))
    {
        if(content2.compare(content1) == 0)
            return id1 < id2;
        else
            return content1 < content2;
    }

    return false;
}

vector<string> reorderLogFiles(vector<string>& logs) {
    // 1. use stable_sort to sort the vecotr
    stable_sort(logs.begin(), logs.end(), comparator);
    return logs;
}*/

vector<string> reorderLogFiles(vector<string>& logs)
{
    if(logs.empty()) return logs;
   vector<string> output;

   vector<string> llog;
   vector<string> dlog;

   for(string &log: logs)
   {
       if(isdigit(log[log.find(" ")+1]))
            dlog.push_back(log);
        else
            llog.push_back(log);
   }

   sort(llog.begin(), llog.end(), [](const string &s1, const string &s2)
   {
       string content1 = s1.substr(s1.find(" ")+1);
       string content2 = s2.substr(s2.find(" ")+1);

       if(content1 == content2)
       {
           return s1.substr(0, s1.find(" ")) < s2.substr(0, s2.find(" "));
       }
        return content1 < content2;
   });

   for(string &log: llog)
   {
       output.push_back(log);
   }

   for(string &log: dlog)
   {
       output.push_back(log);
   }

   return output;
}

int main()
{
    vector<string> logs  = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};

    vector<string> output = reorderLogFiles(logs);

    for(unsigned int i =0; i<output.size(); i++)
    {
        cout << output[i] << "\n";
    }
    string rest1 = "1234";
    string rest2 = "4312";

    bool test = rest1 < rest2;

    if(test == true)
        cout << "\nTrue\n";
    return 0;
}