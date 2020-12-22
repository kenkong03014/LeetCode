#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
using namespace std;

//Best Time to Buy and Sell Stock.
int maxProfit(vector<int>& prices) {
    
    if(prices.size() == 0 || prices.size() == 1)
        return 0;
    int smallest = prices[0], profit = 0;
    for(int i = 0; i< prices.size(); i++)
    {
        if(prices[i] - smallest > profit)
            profit = prices[i] - smallest;
        if(prices[i] < smallest)
            smallest = prices[i];
    }

    return profit;
}
int main()
{
    vector<int> maxprofit1 = {7,1,5,3,6,4};
    vector<int> maxprofit2 = {7,6,4,3,1};

    int profit = maxProfit(maxprofit1);
    cout << "profit1 is: " << profit << endl;
    profit = maxProfit(maxprofit2);
    cout << "profit2 is: " << profit << endl;
    return 0;
}