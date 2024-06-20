#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;

class LargeInteger 
{
    public:
    vector<int> digits; // Use an array/vector to store digits

    LargeInteger() {}

    LargeInteger(const string& numStr) 
    {
        for (int i = numStr.length() - 1; i >= 0; i--) {
            digits.push_back(numStr[i] - '0');
        }
    }

    LargeInteger operator*(const LargeInteger& other) const 
    {
        LargeInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (size_t i = 0; i < digits.size(); i++) 
        {
            for (size_t j = 0, carry = 0; j < other.digits.size() || carry; j++) 
            {
                long long cur = result.digits[i + j] +
                                (i < digits.size() ? digits[i] : 0) *
                                (j < other.digits.size() ? other.digits[j] : 0) +
                                carry;
                result.digits[i + j] = cur % 10;
                carry = cur / 10;
            }
        }

        // Remove leading zeros
        while (result.digits.size() > 1 && result.digits.back() == 0) 
        {
            result.digits.pop_back();
        }
        return result;
    }
};

int main() 
{
    string prime1, prime2;
    // Read the large integers as strings from the file
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file!" << std::endl;
        return 1;
    }

    if (!(inputFile >> prime1 >> prime2)) {
        std::cerr << "Failed to read large integers from the file!" << std::endl;
        inputFile.close();
        return 1;
    }

    inputFile.close();
    LargeInteger largeInt1(prime1);
    LargeInteger largeInt2(prime2);

    // Perform multiplication of largeInt1 and largeInt2
    LargeInteger result = largeInt1 * largeInt2;

    // Print the result
    cout << "Multiplication result: ";
    for (int i = result.digits.size() - 1; i >= 0; i--) 
    {
        cout << result.digits[i];
    }
    cout << endl;

    return 0;
}
