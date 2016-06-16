class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        tweets_sofar = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {

        user_tweets[userId].push_back(tweetId);
        tweet_timestamp[tweetId] = tweets_sofar++;
        // add to itself news feed
        user_newsfeed[userId].push_back(make_pair(userId, tweetId));

        for (auto ite = user_followers[userId].begin(); ite != user_followers[userId].end(); ite++) {
            user_newsfeed[*ite].push_back(make_pair(userId, tweetId));
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feeds;
        const vector<pair<int, int> > &tweets = user_newsfeed[userId]; 
        for (int i = tweets.size() - 1; i >= 0 && feeds.size() < 10; i--) {
            auto tweet = tweets[i];
            feeds.push_back(tweet.second);
        }
        return feeds;        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        // invalid op
        if (followerId == followeeId) return;


        if (user_following[followerId].count(followeeId) == 0) {
            user_following[followerId].insert(followeeId);
            user_followers[followeeId].insert(followerId);

            auto &tweets = user_tweets[followeeId];
            auto &newsfeed = user_newsfeed[followerId]; 
            for (auto ite = tweets.begin(); ite != tweets.end(); ite++) {
                newsfeed.push_back(make_pair(followeeId, *ite));
            }

            auto comp = [this](const pair<int, int>& lhs, const pair<int, int>& rhs) {
                return tweet_timestamp[lhs.second] < tweet_timestamp[rhs.second];
            };
            sort(newsfeed.begin(), newsfeed.end(), comp);
        }                
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        // invalid op
        if (followerId == followeeId) return;

        auto ite = user_following[followerId].find(followeeId);
        if (ite != user_following[followerId].end()) {
            user_following[followerId].erase(ite);

            auto &newsfeed = user_newsfeed[followerId];
            vector<pair<int, int>> newsfeed_aux;
            std::swap(newsfeed, newsfeed_aux);
            for (auto feed_ite = newsfeed_aux.begin(); feed_ite != newsfeed_aux.end(); feed_ite++) {
                auto userId = (*feed_ite).first;
                if (userId == followerId || user_following[followerId].count(userId) > 0) {
                    newsfeed.push_back(*feed_ite);
                }
            }
        }

        ite = user_followers[followeeId].find(followerId);
        if (ite != user_followers[followeeId].end()) {
            user_followers[followeeId].erase(ite);
        }
        
    }
private:
    unordered_map<int, unordered_set<int> > user_following;
    unordered_map<int, unordered_set<int> > user_followers;
    unordered_map<int, vector<pair<int, int>> > user_newsfeed;
    unordered_map<int, vector<int> > user_tweets;
    unordered_map<int, uint64_t> tweet_timestamp;
    uint64_t tweets_sofar;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */