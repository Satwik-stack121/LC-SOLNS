class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stoneh; 
        for(int i : stones){
            stoneh.push(i);
        }

        while(stoneh.size() != 1){
            int y=stoneh.top();
            stoneh.pop();
            int x=stoneh.top();
            stoneh.pop();

            if(x != y){
                stoneh.push(y-x);
            }
            if(stoneh.size()== 0){
                return 0;
            }
        }
        return stoneh.top();
    }
};
