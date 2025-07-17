class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if ((s[left] > 'Z' || s[left] < 'A') && 
                (s[left] > 'z' || s[left] < 'a') && 
                (s[left] < '0' || s[left] > '9')) {
                left++;
                continue;
            }
            else if ((s[right] > 'Z' || s[right] < 'A') && 
                     (s[right] > 'z' || s[right] < 'a') && 
                     (s[right] < '0' || s[right] > '9')) {
                right--;
                continue;
            }
            else if (tolower(s[left++]) != tolower(s[right--])) return false; 
        }
        return true;  
    }
};