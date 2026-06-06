class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        vector<vector<int>> freqindex(nums.size() + 1);
        for(auto& [num, freq] : counts){
            freqindex[freq].push_back(num);
        }
        vector<int> result;
        for (int i =freqindex.size() - 1; i>= 0; i--) {
            for (int num : freqindex[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
