#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && !(n & (n - 1));
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int findUnique(vector<int>& arr) {
    int result = 0;
    for (int num : arr) result ^= num;
    return result;
}

int main() {
    cout << "Power of two (16): " << isPowerOfTwo(16) << "\n";
    cout << "Power of two (18): " << isPowerOfTwo(18) << "\n";
    cout << "Set bits (29): " << countSetBits(29) << "\n";
    vector<int> arr = {4, 2, 1, 2, 1};
    cout << "Unique element: " << findUnique(arr) << "\n";
    return 0;
}
