#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> convertToBinary(const vector<int>& numbers) {
    int maxDigits = 0;
    for (int num : numbers) {
        int digits = 0;
        while (num > 0) {
            num /= 2;
            digits++;
        }
        maxDigits = max(maxDigits, digits);
    }

    vector<string> binaryStrings;
    for (int num : numbers) {
        string binaryRep;
        while (num > 0) {
            binaryRep = to_string(num % 2) + binaryRep;
            num /= 2;
        }
        while (binaryRep.length() < maxDigits) {
            binaryRep = "0" + binaryRep;
        }
        binaryStrings.push_back(binaryRep);
    }

    return binaryStrings;
}

int main() {
    vector<int> numbers = {5, 10, 3, 7, 15};
    vector<string> binaryReps = convertToBinary(numbers);

    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << ": " << binaryReps[i] << endl;
    }

    return 0;
}
