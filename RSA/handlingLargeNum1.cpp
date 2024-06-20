#include <iostream>
#include <vector>
using namespace std;

const int ARRAY_SIZE = 2048;  // Number of 32-bit elements in the array

using BigInt = vector<uint32_t>;  // Using vector as a dynamic array

// Helper function to add two arrays
void addArrays(const BigInt &a, const BigInt &b, BigInt &result) {
    uint32_t carry = 0;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        uint64_t sum = static_cast<uint64_t>(a[i]) + b[i] + carry;
        result[i] = static_cast<uint32_t>(sum);
        carry = static_cast<uint32_t>(sum >> 32);
    }
}

// Helper function to multiply a 2048-bit number by a 32-bit number
void multiplyBy32Bit(const BigInt &num, uint32_t factor, BigInt &result) {
    uint32_t carry = 0;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        uint64_t product = static_cast<uint64_t>(num[i]) * factor + carry;
        result[i] = static_cast<uint32_t>(product);
        carry = static_cast<uint32_t>(product >> 32);
    }
}

int main() 
{
    // Initialize 2048-bit numbers
    BigInt num1(ARRAY_SIZE);
    BigInt num2(ARRAY_SIZE);
    BigInt result(2*ARRAY_SIZE);

    // Set values for num1 and num2
    num1[0] = 123479641647;  // Example value
    num2[0] = 56456456546546;  // Example value

    // Perform addition
    //addArrays(num1, num2, result);

    // Print the result of addition
    cout << "Addition Result: ";
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    // Perform multiplication by a 32-bit factor
    uint32_t factor = 123;  // Example factor
    multiplyBy32Bit(num1, factor, result);

    // Print the result of multiplication
    cout << "Multiplication Result: ";
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        cout << result[i] << " ";
    }
    cout <<endl;

    return 0;
}