#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void println(vector<int>v){
    for(int ele : v){
        cout<<ele<<" ";
    }
    cout<<endl;
}

struct Tweet{
    int time;
    int tweetId;
    Tweet(int t, int id): time(t), tweetId(id) {}
};

class Twitter {
    int time;
    unordered_map<int,vector<Tweet>>tweets;
    unordered_map<int,set<int>>follows;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time++,tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>maxHeap;
        vector<int>newsFeed;
        int count = 0;
        for(Tweet tweet: tweets[userId]){
            maxHeap.push(make_pair(tweet.time,tweet.tweetId));
        }
        for(int uid : follows[userId]){
            vector<Tweet>twts = tweets[uid];
            for(Tweet tweet: twts){
                maxHeap.push(make_pair(tweet.time,tweet.tweetId));
            }
        }
        while(!maxHeap.empty() && count < 10){
            newsFeed.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follows[followerId].erase(followeeId);
    }
};

int main(){
    // easy test case
    Twitter* obj = new Twitter(); 
    obj->postTweet(1,5); 
    vector<int> param_1 = obj->getNewsFeed(1); 
    println(param_1); obj->follow(1,2); 
    obj->postTweet(2,6); 
    vector<int> param_2 = obj->getNewsFeed(1); 
    println(param_2); obj->unfollow(1,2); 
    vector<int> param_3 = obj->getNewsFeed(1); 
    println(param_3);

    //complex test case
    // Twitter* obj = new Twitter();

    // obj->postTweet(1, 6765);
    // obj->postTweet(5, 671);
    // obj->postTweet(3, 2868);
    // obj->postTweet(4, 8148);
    // obj->postTweet(4, 386);
    // obj->postTweet(3, 6673);
    // obj->postTweet(3, 7946);
    // obj->postTweet(3, 1445);
    // obj->postTweet(4, 4822);
    // obj->postTweet(1, 3781);
    // obj->postTweet(4, 9038);
    // obj->postTweet(1, 9643);
    // obj->postTweet(3, 5917);
    // obj->postTweet(2, 8847);

    // obj->follow(1, 3);
    // obj->follow(1, 4);
    // obj->follow(4, 2);
    // obj->follow(4, 1);
    // obj->follow(3, 2);
    // obj->follow(3, 5);
    // obj->follow(3, 1);
    // obj->follow(2, 3);
    // obj->follow(2, 1);
    // obj->follow(2, 5);
    // obj->follow(5, 1);
    // obj->follow(5, 2);

    // vector<int> f1 = obj->getNewsFeed(1);
    // println(f1);

    // vector<int> f2 = obj->getNewsFeed(2);
    // println(f2);

    // vector<int> f3 = obj->getNewsFeed(3);
    // println(f3);

    // vector<int> f4 = obj->getNewsFeed(4);
    // println(f4);

    // vector<int> f5 = obj->getNewsFeed(5);
    // println(f5);

    return 0;
}
