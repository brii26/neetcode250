class Solution {
public:
    void dfs(vector<int> path , vector<vector<int>> &res, vector<bool> &seen, vector<int> &nums) {
        if(nums.size() == path.size()) {
            res.push_back(path);
        }

        int n = nums.size();
        unordered_set<int> set;
        for(int i = 0 ; i < n ; i++) {
            if (seen[i] || set.contains(nums[i])) {
                continue;
            }
            path.push_back(nums[i]);
            set.insert(nums[i]);
            seen[i] = true;
            dfs(path, res, seen, nums);
            seen[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> seen(8,false);
        dfs({},res,seen, nums);
        return res;
    }
};