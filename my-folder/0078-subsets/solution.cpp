class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& soln , int start){

        soln.push_back(current); 
        for (int i = start; i < nums.size(); ++i){
            current.push_back(nums[i]);
            backtrack(nums, current, soln, i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> soln;
        vector<int> current;
        backtrack(nums, current, soln, 0);
        return soln;
        

    }
};
