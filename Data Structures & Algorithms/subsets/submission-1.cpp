class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0,nums,path,res);
        return res;
    }
private:
    void backtrack (int start, vector<int> &nums, vector<int> &path, vector<vector<int>> &res) {
        res.push_back(path);
        int n = nums.size();
        for (int i = start ; i < n; i++) {
            path.push_back(nums[i]);
            backtrack(i+1, nums, path, res);
            path.pop_back();
        }
    }
};
