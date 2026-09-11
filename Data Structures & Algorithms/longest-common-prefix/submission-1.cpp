class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res = "";

        // smallest lenght
        string bm = strs[0];
        for(string s : strs) {
            bm = (s.size() < bm.size()) ? s : bm;
        }

        // core iteration
        int m = bm.size();
        for (int i = 0 ; i < m ; i++) {
            char val = bm[i];
            for (int j = 0 ; j < n ; j++) {
                if (strs[j][i] != val) {
                    return res;
                }
            }
            res += val;
        }
        return res;
    }
};