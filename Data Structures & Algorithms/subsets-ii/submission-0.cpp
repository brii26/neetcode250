class Solution {
public:

    void dfs(int idx, vector<int> &nums, vector<int> path, vector<vector<int>> &res,
    vector<bool> &seen) {
        res.push_back(path);

        int n = nums.size();

        unordered_set<int> set;
        for(int i = idx; i < n; i++ ) {
            if (set.contains(nums[i])) {
                continue;
            }
            set.insert(nums[i]);
            path.push_back(nums[i]);
            seen[i] = true;
            dfs(i+1, nums, path , res, seen);
            seen[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> seen(11,false);
        sort(nums.begin(),nums.end());
        dfs(0,nums,{},res,seen);
        return res;
    }
};
