#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
using namespace std;

//n^2
// int maxSubArray(vector<int>& nums) {
//     if(nums.size() == 0 )
//         return 0;
//     else if(nums.size() == 1)
//         return nums[0];
    
//     int tmp;
//     int largest = nums[0];

//     for(int i = 0; i<nums.size(); i++)
//     {
//         tmp = nums[i];
//         for(int j = i+1; j < nums.size(); j++)
//         {
//             tmp = tmp + nums[j];
//             if(tmp >= largest)
//                 largest = tmp;
//         }

//         if(nums[i] >= largest)
//             largest = nums[i];
//     }

//     return largest;
// }

//Divide and conquer
// int maxSubArray(vector<int>& nums) {
//     if(nums.size() == 1)
//     {
//         return nums[0];
//     }
  
//     int half = nums.size()/2;
//     int rightcount = 0;

//     vector<int> leftnum(half);
//     vector<int> rightnum(nums.size()-half);

//     for(int i =0; i < half; i++)
//     {
//         leftnum[i] = nums[i];
//     }
//     for(int i =half; i < nums.size(); i++)
//     {
//         rightnum[rightcount] = nums[i];
//         rightcount++;
//     }

//     int leftmss = maxSubArray(leftnum);
//     int rightmss = maxSubArray(rightnum);

//     int leftsum = -INT_MAX, rightsum = -INT_MAX, sum = 0;


//     for(int i =0; i< rightnum.size(); i++)
//     {
//         sum += rightnum[i];
//         rightsum = max(rightsum, sum);
//     }

//     sum = 0;

//     for(int i = leftnum.size()-1; i>=0; i--)
//     {
//         sum += leftnum[i];
//         leftsum = max(leftsum, sum);
//     }
//     int maxMSS = max(leftmss, rightmss);

//     return max(maxMSS, leftsum+rightsum);
// }

// linear
int maxSubArray(vector<int>& nums)
{
    int local = 0, global = -INT_MAX;
    for(int i = 0; i < nums.size(); i++)
    {
        //Keep adding current number if it is not negative
        local += nums[i];
        //If the local max > than global max, than change it
        if(local >= global)
            global = local;
        /** If the local is negative, than we reset it to 0, which means the
         * current number is not good. We will keep the local if it is still
         * positive
         */ 
        if(local < 0)
            local = 0;
    }

    return global;
}
int main()
{
    vector<int> maxsub = {8,-19,5,-4,20};

    int greatest = maxSubArray(maxsub);

    cout << "greatest: " << greatest << endl;

    return 0;
}