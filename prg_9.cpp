#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;


int maxDifference(const vector<int>& nums) {
    if (nums.size() < 2) {
        throw invalid_argument("Array must contain at least two elements.");
    }
   
    int minElement = INT_MAX;
    int maxElement = INT_MIN;
   
    for (int num : nums) {
        if (num < minElement) {
            minElement = num;
        }
        if (num > maxElement) {
            maxElement = num;
        }
    }
   
    return maxElement - minElement;
}


int main() {
    vector<int> nums = {1, 2, 9, 4, 5}; 
    try {
        cout << "The maximum difference between any two elements is: " << maxDifference(nums) << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }


    return 0;
}
