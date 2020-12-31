#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
using namespace std;

/**
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count = 0;

        for(int i = m; i<m+n;i++)
        {
            nums1[i] = nums2[count];
            count++;
        }

        sort(nums1.begin(), nums1.end());
}
*/

/**
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    int p1 = 0;
    int p2 = 0;
    int innerCount = 0;
    while(innerCount != m && p2 != n)
    {
        if(nums1[p1] < nums2[p2])
        {
            p1++;
            innerCount++;
        }
        else
        {
            nums1.insert(nums1.begin()+p1, nums2[p2]);
            nums1.pop_back();
            p2++;
            p1++;
        }
    }
    cout << "p2: " << p2 << endl;
    if(p2 != n)
    {
        while(p2 != n)
        {
            nums1[innerCount+p2] = nums2[p2];
            p2++;
        }
    }
}
*/

// O(m+n) and O(1) space
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, pos = n+m-1;
        while (i >= 0 && j >= 0) {
            cout << i << ":" << j << ". "<< nums1[i] << " >= " << nums2[j] << " ? " << nums1[i-1] << " : " << nums2[j-1] << endl;
            //condition ? return_if_true : return_if_false;
            nums1[pos--] = (nums1[i] >= nums2[j]) ? nums1[i--] : nums2[j--];
            cout << "nums1[pos--]: " << nums1[pos+1] << endl << endl;
        }
        
        while (j >= 0) {
            nums1[pos--] = nums2[j--];
        }
}

int main()
{
    vector<int> nums1 = {4,0,0,0,0,0};
    vector<int> nums2 = {1,2,3,5,6};

    merge(nums1, 1, nums2, nums2.size());
    for(int i =0; i < (int)nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << "\n\n";
    nums2.insert(nums2.begin()+1, 3);
    for(int i =0; i < (int)nums2.size(); i++)
    {
        cout << nums2[i] << " ";
    }
    cout << "\n";
    return 0;
}