#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void reverseArray(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}


void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverseArray(nums, 0, n - 1);
    reverseArray(nums, 0, k - 1);
    reverseArray(nums, k, n - 1);
}


int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
   
    rotate(nums, k);
   
    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}
