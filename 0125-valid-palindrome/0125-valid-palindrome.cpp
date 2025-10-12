class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(),
                [](unsigned char c){ return !isalnum(c); }),
        s.end());

        for (char &c : s) 
        c = std::tolower(static_cast<unsigned char>(c));

        int left = 0;
        int right = s.size()-1;

        bool isPalindrome = true;

        while(left < right){
            if(s[left] != s[right]){
                isPalindrome = false;
                break;
            }
            left++;
            right--;
        }

        return isPalindrome;
    }
};