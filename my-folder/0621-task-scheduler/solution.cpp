class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char c : tasks){
            freq[c-'A']++;
        }
        priority_queue<pair<int,char>> pq;

        for(int  i=0; i < 26; i++){
            if(freq[i] > 0){
                pq.push({freq[i], char('A' + i)});
            }
        }
        vector<char> process;
        while(pq.size() != 0){
            vector<pair<int,char>> poped;
            int spacing =0;

            for(int i=0; i<=n; i++){
                if(pq.size() == 0){
                    break;
                }
                pair<int , char> task =pq.top();
                pq.pop();
                process.push_back(task.second);
                task = {task.first -1 , task.second};

                if(task.first){
                    poped.push_back(task);
                }
                spacing++;
            }
            for(pair<int , char> curr : poped){
                pq.push(curr);
            }
            if (!pq.empty()){
                while(spacing <=n){
                    process.push_back('_');
                    spacing++;
                }
            }
        }
        return process.size();
    }
};
