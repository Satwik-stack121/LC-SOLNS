class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> answer(temperatures.size(), 0);
        stack<int> indices;

        for(int curr= 0; curr < temperatures.size(); ++curr){
            while(!indices.empty() && temperatures[curr]> temperatures[indices.top()]){
                answer[indices.top()]=curr-indices.top();
                indices.pop();
            }
            indices.push(curr);
        }
    return answer;
    }
};
