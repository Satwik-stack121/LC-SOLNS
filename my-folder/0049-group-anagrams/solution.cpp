class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> sorted;
        
        for(int i=0; i<strs.size(); i++){
            string sortedStr= strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            sorted.push_back({sortedStr, i});
        }
        
        sort(sorted.begin(), sorted.end());
        vector<vector<string>> result;
        if(sorted.empty()) return result;
        vector<string> current;
        current.push_back(strs[sorted[0].second]);
        
        for(int i= 1; i<sorted.size(); i++) {
            if (sorted[i].first == sorted[i - 1].first){
                current.push_back(strs[sorted[i].second]);
            }
            else{
                result.push_back(current);
                current.clear();
                current.push_back(strs[sorted[i].second]);
            }
        }
        result.push_back(current);
        
        return result;        
    }
};
