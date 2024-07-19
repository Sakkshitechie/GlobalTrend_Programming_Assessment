#include <iostream>
#include <string>
#include <cctype>


using namespace std;


bool isAlphabetic(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}


int main() {
    string testStr1 = "HelloWorld";  
    string testStr2 = "Hello123";    


    cout << "The string \"" << testStr1 << "\" contains only alphabetic characters: " << (isAlphabetic(testStr1) ? "true" : "false") << endl;
    cout << "The string \"" << testStr2 << "\" contains only alphabetic characters: " << (isAlphabetic(testStr2) ? "true" : "false") << endl;


    return 0;
}
