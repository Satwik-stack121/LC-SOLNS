class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> connections (numCourses);
        vector<int> indegree (numCourses);

        for(vector<int> i : prerequisites){
            int a = i[0];
            int b = i[1];
            connections[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            count++;
            for(int i : connections[curr]){
                indegree[i]--;
            }
            for(int i : connections[curr]){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(count == numCourses){
            return true;
        }
        return false;
    }
};
