class Solution {
public:
    bool validPalindrome(string s) {
        bool unmatch = false;
        int l=0;
        int r = s.size()-1;
        int l1 = -1;
        int r1 = -1;
        int l2 = -1;
        int r2 = -1;

        while (r > l ) {
            if (s[r] != s[l]) {
                unmatch = true;
                l1 = l+1;
                l2 = l;
                r1 = r;
                r2 = r-1;
                break;
            }
            --r;
            ++l;
        }
        if (!unmatch) return true;

        //scenario 1
        bool s1 = true;
        while (r1 > l1) {
            if (s[r1--] != s[l1++]) {
                s1 = false;
                break;
            }
        }

        // scenario 2
        bool s2 = true;
        while (r2 > l2) {
            if (s[r2--] != s[l2++]) {
                s2 = false;
                break;
            }
        }
        return s1 || s2;
    }
};