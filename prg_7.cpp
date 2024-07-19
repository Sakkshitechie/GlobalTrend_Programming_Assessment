#include <iostream>


using namespace std;


int sumOfDigits(int n) {
    int sum = 0;
    n = abs(n); 
    while (n > 0) {
        sum += n % 10; 
        n /= 10;       
    }
    return sum;
}


int main() {
    int number = 56789; 
    cout << "Sum of the digits of " << number << " is " << sumOfDigits(number) << endl;


    return 0;
}
