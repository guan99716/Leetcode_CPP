#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            // here we add i < j constraint is to avoid ".," this kind of test set that contains no alnum char,
            // i will keep adding and overflow
            while (i < j && !isalnum(s[i]))
                i++;
            while (i < j && !isalnum(s[j]))
                j--;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};