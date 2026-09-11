class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1 = word1.size();
        int w2 = word2.size();
        int n = (w1 > w2) ? w1 : w2;

        string res = "";
        for (int i = 0; i < n ; i++) {
            if(i<w1) res+=word1[i];
            if(i<w2) res+=word2[i];
        }
        return res;
    }
};