#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int longest = 0;
    int start = 0;


    for (int end = 0; end < s.length(); ++end) {
        if (charIndexMap.find(s[end]) != charIndexMap.end()) {
            start = max(start, charIndexMap[s[end]] + 1);
        }
        charIndexMap[s[end]] = end;
        longest = max(longest, end - start + 1);
    }


    return longest;
}


int main() {
    string s = "abcabcbb";
    std::cout << "The length of the longest substring without repeating characters is: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
