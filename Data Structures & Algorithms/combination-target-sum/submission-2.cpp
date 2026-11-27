class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        vector<vector<int>> res;
        backtrack(0,0,target,nums,path,res);
        return res; 
    }
private:
    void backtrack(int start, int sum, int target, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        int n = nums.size();
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = start ; i < n ; i++) {
            path.push_back(nums[i]);
            sum+=nums[i];
            backtrack(i, sum, target, nums, path, res);
            sum-=nums[i];
            path.pop_back();
        }
    }
};
