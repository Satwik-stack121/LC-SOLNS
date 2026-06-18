class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const auto& a , const auto& b){
            return a.first < b.first; 
        };

        vector<vector<int>> ans;

        priority_queue<pair<int , int>, vector<pair<int, int>> , decltype(cmp)> pq; 
        int index=0;
        for(const vector<int>& i : points){
            int dist = i[0]*i[0] + i[1]*i[1];
            pair<int , int> pairs = {dist , index};
            index++;
            pq.push(pairs);
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(pq.size() != 0){
            pair<int , int> i = pq.top();
            pq.pop();
            ans.push_back(points[i.second]);
        }
        return ans;
    }
};
