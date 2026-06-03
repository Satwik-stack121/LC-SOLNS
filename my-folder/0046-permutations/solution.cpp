class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>&current , vector<vector<int>>&  solution, unordered_set<int>& used){
        if(current.size()==nums.size()){
            solution.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used.contains(nums[i])){
                continue;
            }
            current.push_back(nums[i]);
            used.insert(nums[i]);

            backtrack(nums, current, solution, used);
            
            current.pop_back();
            used.erase(nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int> current;
        unordered_set<int> used;
        backtrack(nums, current, solution, used);
        return solution;
    }
};
