class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> post;

        int carfleet=0;

        for(int i=0; i < position.size(); i++){
            double time=(double)(target-position[i])/speed[i];

            post.push_back({position[i], time});
        }
        sort(post.rbegin(), post.rend());

        double curr=0.0;
        for(int i=0;i< position.size(); i++){   
            if(post[i].second > curr){
                carfleet++;
                curr=post[i].second;
            }
        }
        return carfleet;

    }
};
