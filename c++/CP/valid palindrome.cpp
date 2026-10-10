#include <iostream>
#include <string>
#include <cctype>

// Put your Solution class here
class Solution {
public:
    bool isPalindrome(std::string s) {
        int i = 0, j = s.length() - 1;
        while(i <= j){
            s[i] = std::tolower(s[i]);
            s[j] = std::tolower(s[j]);
            std::cout << s[i] << "\n";
            while(i <= j && (s[i] > 'z' || s[i] < 'a') && (s[i] > '9' || s[i] < '0'))
                i++;
            while(i <= j && (s[j] > 'z' || s[j] < 'a') && (s[j] < 'a' || s[j] > '9' || s[j] < '0'))
                j--;
            std::cout << s[j] << "\n";
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else
                break;
        }
        return i > j;
    }
};

int main() {
    Solution sol;
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (sol.isPalindrome(input)) {
        std::cout << "Result: true (Valid Palindrome)\n";
    } else {
        std::cout << "Result: false (Not a Palindrome)\n";
    }

    return 0;
}