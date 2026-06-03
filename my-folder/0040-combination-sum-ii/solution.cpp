class Solution {
public:

    void backtrack(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& soln){
        if(target==0){
            
            soln.push_back(current);
        }
        if(target<0 || index>=candidates.size()){
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(candidates[i]>target){
                break;
            }
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            current.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i+1, current, soln);
            current.pop_back();
        }
        // current.push_back(candidates[index]);
        // backtrack(candidates, target-candidates[index], index+1, current, soln);
        // current.pop_back();
        // backtrack(candidates, target, index+1, current, soln);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> soln;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, soln);

        return soln;
    }
};
