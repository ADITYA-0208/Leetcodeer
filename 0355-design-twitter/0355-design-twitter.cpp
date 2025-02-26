class Twitter {
private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets; 
    unordered_map<int, unordered_set<int>> followers;  

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; 
        for (auto& t : tweets[userId]) {
            pq.push(t);
        }

        for (int followeeId : followers[userId]) {
            for (auto& t : tweets[followeeId]) {
                pq.push(t);
            }
        }

        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
