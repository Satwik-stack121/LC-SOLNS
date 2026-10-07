class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> soln;
        int n = s.size();
        int start = 0;
        vector<int> store(26);
        for (int i = 0; i < n; i++) {
            store[s[i] - 'a'] = i;
        }

        while(start < n){
            int boundry = store[s[start] - 'a'];
            for(int j = start ; j < boundry ; j++){
                int curr = store[s[j] - 'a'];
                if(curr > boundry){
                    boundry = curr;
                }
            }
            soln.push_back(boundry - start +1);
            start = boundry+1;
        }

        return soln;
    }
};
