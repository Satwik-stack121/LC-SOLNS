class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_length = 0;

        for (const int& i : num_set) {
            if (num_set.find(i-1) != num_set.end()){
                continue;
            }
            int current_len = 1;
        
            while (num_set.find(i+current_len) != num_set.end()){
                current_len++;
            }

            if (max_length < current_len){
                max_length = current_len;
            }
        }

        return max_length;
    }
};
