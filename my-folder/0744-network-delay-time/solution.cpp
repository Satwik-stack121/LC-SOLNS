class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto & i : times){
            int u = i[0];
            int v=i[1];
            int w = i[2];

            adj[u].push_back({v , w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0; 
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int,int>>> pq ;
        pq.push({0, k});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dist[u]){
                continue;
            }

            for(auto & i : adj[u]){
                int v = i.first;
                int w = i.second;

                if(d + w < dist[v]){
                    dist[v] = d+w;
                    pq.push({dist[v], v});
                }

            }
        }

        int ans=0;
        for(int i = 1 ; i < n+1 ; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }

            ans = max(ans , dist[i]);
        }

        return ans;
    }
};   
