/**
 * @file gray_code.cpp
 * @brief Solution for the Gray Code sequence generation problem.
 * * Binary to Gray Code Formula:
 * ----------------------------
 * Mathematical Rule:
 * G_n = B_n                 (Most Significant Bit stays the same)
 * G_i = B_{i+1} XOR B_i     (Each remaining bit is XORed with the bit to its left)
 * * Bitwise Implementation:
 * gray = i ^ (i >> 1);
 * * Constraints: 1 <= n <= 16
 * Time Complexity: O(2^n)
 * Space Complexity: O(1)
 */
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    // total_rows = 2^n computed using bitwise left shift
    int total_rows = 1 << n; 
    // Iterate through all decimal indices from 0 to (2^n - 1)
    for (int i = 0; i < total_rows; i++) {
        // Apply the Bitwise Formula: i XOR (i Right Shift 1)
        int gray = i ^ (i >> 1);
        // Extract and print bits from MSB to LSB
        for (int bit = n - 1; bit >= 0; bit--) {
            cout << ((gray >> bit) & 1);
        }
        cout << "\n";
    }
    return 0;
}
