class Twitter {
public:
    int timestamp=0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    Twitter() {
        
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> all;
        for (pair<int,int> tweet:tweets[userId]){
            all.push_back(tweet);
        }
        for(int followee:following[userId]){
            for(pair<int,int> tweet:tweets[followee]){
                all.push_back(tweet);
            }
        }
        sort(all.begin(),all.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });
        vector<int> ans;
        for (int i=0;i<10 && i<all.size();i++) {
            ans.push_back(all[i].second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
