#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
#include <unordered_map>
using namespace std;

/** n^2
int findExisted(vector<pair<string, int>>& domains, string s1)
{
    if(domains.size() == 0)
        return 0;

    for(int i = 0; i< (int) domains.size(); i++)
    {
        if(domains[i].first == s1)
            return i;
    }

    return -1;
}

vector<string> subdomainVisits(vector<string>& cpdomains) {
    int num, space, firstDot, secondDot;
    string middle, top;
    vector<pair<string, int>> topLevel;
    vector<pair<string, int>> midLevel;
    vector<string> res;
    int topCheck = 0;
    int midCheck = 0;

    for(int i = 0; i < (int)cpdomains.size(); i++)
    {
        space = cpdomains[i].find(" ");
        num = stoi(cpdomains[i].substr(0,space));
        firstDot = cpdomains[i].find(".");
        secondDot = cpdomains[i].rfind(".");
        
        if(firstDot != secondDot)
        {
            res.push_back(cpdomains[i]);
            middle = cpdomains[i].substr(firstDot+1);
            midCheck = findExisted(midLevel, middle);
            if(midCheck >= 0)
            {
                if(midLevel.size() != 0)
                    midLevel[midCheck].second += num;
                else
                   midLevel.emplace_back(middle, num); 
            }
            else
                midLevel.emplace_back(middle, num);
        }
        else
        {
            middle = cpdomains[i].substr(space+1);
            midCheck = findExisted(midLevel, middle);
            if(midCheck >= 0)
            {
                if(midLevel.size() != 0)
                    midLevel[midCheck].second += num;
                else
                   midLevel.emplace_back(middle, num); 
            }
            else
                midLevel.emplace_back(middle, num);
        }
        
        top = cpdomains[i].substr(secondDot+1);
        topCheck = findExisted(topLevel, top);

        if(topCheck >= 0)
        {
            if(topLevel.size() != 0)
                topLevel[topCheck].second += num;
            else
                topLevel.emplace_back(top, num);
        }
        else
            topLevel.emplace_back(top, num);
    }
    for(int i =0; i<(int)topLevel.size(); i++)
    {
        res.push_back(to_string(topLevel[i].second) + " " + topLevel[i].first);
    }

    for(int i =0; i<(int)midLevel.size(); i++)
    {
        res.push_back(to_string(midLevel[i].second) + " " + midLevel[i].first);
    }

    return res;
}
*/

/**
vector<string> subdomainVisits(vector<string>& cpdomains)
{
    vector<string> res;
    unordered_map<string, int> info;
    int space;
    int num;
    string domains;

    for(int i=0; i<(int)cpdomains.size(); i++)
    {
        space = cpdomains[i].find(" ");
        num = stoi(cpdomains[i].substr(0,space));
        domains = cpdomains[i].substr(space+1);
        info[domains] += num;
        for(int j =0; j < (int)domains.size(); j++)
        {
            if(domains[j] == '.')
                info[domains.substr(j+1)] += num;
        }
    }

    for(auto x : info)
    {
        res.push_back(to_string(x.second)+" " + x.first);
    }

    return res;
}*/

vector<string> subdomainVisits(vector<string>& cpdomains)
{
    vector<string> res;
    unordered_map<string, int> info;
    int num, space, firstDot, secondDot;
    string low, middle, top;

    for(int i=0; i<(int)cpdomains.size(); i++)
    {
        space = cpdomains[i].find(" ");
        num = stoi(cpdomains[i].substr(0,space));
        firstDot = cpdomains[i].find(".");
        secondDot = cpdomains[i].rfind(".");
        
        if(firstDot != secondDot)
        {
            low = cpdomains[i].substr(space+1);
            middle = cpdomains[i].substr(firstDot+1);
            info[low] += num;
            info[middle] += num;
        }
        else
        {
            middle = cpdomains[i].substr(space+1);
            info[middle] += num;
        }

        top = cpdomains[i].substr(secondDot+1);
        info[top] += num;

    }

    for(auto x : info)
    {
        res.push_back(to_string(x.second)+" " + x.first);
    }

    return res;
}

int main()
{
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> res = subdomainVisits(cpdomains);

    for(int i =0; i<(int)res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    // string input = "900 intel.gmail.com";

    // int space = input.find(" ");
    // int num = stoi(input.substr(0, space));
    // int firstDot = input.find(".");
    // string middle = input.substr(firstDot+1);
    // int secondDot = input.rfind(".");
    // string top = input.substr(secondDot+1);

    // cout << "num: " << num << "\n";
    // cout << "Middle: " << middle << "\n";
    // cout << "Top: " << top << "\n";
    return 0;
}