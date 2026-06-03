class Solution {
public:
    void backtrack(vector<int>& candy, int ind, int target, vector<int>& currSoln, vector<vector<int>>& res){
        if(ind >= candy.size() || target < 0)
            return;
        if(target == 0){
            res.push_back(currSoln);
            return;
        }
        currSoln.push_back(candy[ind]);
        backtrack(candy, ind, target - candy[ind], currSoln, res);
        currSoln.pop_back();
        backtrack(candy, ind + 1, target, currSoln, res);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currSoln;

        backtrack(candidates, 0, target, currSoln, res);
        return res;
    }
};
