#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.size() == 0 )
        return 0;
    else if(nums.size() == 1)
        return nums[0];
    
    int tmp;
    int largest = nums[0];

    for(int i = 0; i<nums.size(); i++)
    {
        tmp = nums[i];
        for(int j = i+1; j < nums.size(); j++)
        {
            tmp = tmp + nums[j];
            if(tmp >= largest)
                largest = tmp;
        }

        if(nums[i] >= largest)
            largest = nums[i];
    }

    return largest;
}

int main()
{
    vector<int> maxsub = {-1,0,-2};
    int largest = maxSubArray(maxsub);

    cout << "Largest is: " << largest << endl;
    return 0;
}