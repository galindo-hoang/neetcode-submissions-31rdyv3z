class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            int tmpL = (s[left] >= '0' && s[left] <= '9')
            || (s[left] >= 'a' && s[left] <= 'z')
            || (s[left] >= 'A' && s[left] <= 'Z');

            int tmpR = (s[right] >= '0' && s[right] <= '9')
            || (s[right] >= 'a' && s[right] <= 'z') 
            || (s[right] >= 'A' && s[right] <= 'Z');
            if(!tmpL) {
                ++left;
                continue;
            }
            if(!tmpR) {
                --right;
                continue;
            }
            cout << left << " - " << right << endl;
            if(tolower(s[left], std::locale()) == tolower(s[right], std::locale())) {
                cout << "hello" << endl;
                ++left;
                --right;
            } else {
                return false;
            }
        }
        return true;
    }
};
