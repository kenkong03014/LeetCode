#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int> input;

    MyHashMap() {}
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if(key == (int)input.size())
            input.push_back(value);
        else if(key > (int)input.size())
        {
            input.resize(input.size()+key+1, -1);
            input[key] = value;
        }
        else
        {
            input[key] = value;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(key >= (int)input.size())
            return -1;
        
        return input[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(key < (int)input.size())
            input[key] = -1;
    }
};

int main()
{
    MyHashMap* obj = new MyHashMap();
    obj->remove(14);
    cout << "get4: " << obj->get(4) << endl;
    obj->put(7,3);
    obj->put(11,1);
    obj->put(12,1);
    cout << "get7: " << obj->get(7) << endl;
    obj->put(1,19);
    obj->put(0,3);
    obj->put(1,8);
    obj->put(2,6);

    return 0;
}