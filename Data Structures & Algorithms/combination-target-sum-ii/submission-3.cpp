class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //keep track path , sum, res
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0,0,target,path,res, candidates);
        return res;
    }
private:
    void backtrack(int index, int sum, int target,vector<int>& path, vector<vector<int>> &res, vector<int> &candidates) {
        int n = candidates.size();
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < n; i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            sum+=candidates[i];
            backtrack(i+1, sum, target, path , res, candidates);
            sum-=candidates[i];
            path.pop_back();
        }
    }
};
