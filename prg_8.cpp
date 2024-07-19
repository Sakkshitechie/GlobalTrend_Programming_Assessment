#include <iostream>


using namespace std;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main() {
    int a = 28; 
    int b = 18;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;


    return 0;
}
