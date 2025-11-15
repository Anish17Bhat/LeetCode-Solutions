#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void println(vector<int>v){
    for(int ele : v){
        cout<<ele<<" ";
    }
    cout<<endl;
}

class Twitter {
    int time;
    multimap<int,pair<int,int>,greater<int>>tweet;
    multimap<int,int>follows;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
      tweet.insert({time++,{userId,tweetId}});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 0;
        vector<int>feed;
        auto range = follows.equal_range(userId);
        if(range.first == range.second){
            for(auto ele : tweet){
                if(ele.second.first == userId){
                    count++;
                    feed.push_back(ele.second.second );
                    if(count == 10) return feed;
                }
            }
        }
        else{
            for(auto it = range.first ; it != range.second ; it++){
                int followee = it->second;
                for(auto ele : tweet){
                    if(ele.second.first == followee || ele.second.first == userId){
                        count++;
                        feed.push_back(ele.second.second );
                        if(count == 10) return feed;
                    }
                }
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        auto range = follows.equal_range(followerId);
        for(auto it = range.first ; it != range.second ; it++) {
            if(it->second == followeeId) return;
        }
        follows.insert({followerId,followeeId});
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        auto range = follows.equal_range(followerId);
        for(auto it = range.first ; it != range.second ; it++){
            if(it->second == followeeId) {
                follows.erase(it);
                break;
            }  
        }
    }
};

int main(){
    Twitter* obj = new Twitter();
    obj->postTweet(1,5);
    vector<int> param_1 = obj->getNewsFeed(1);
    println(param_1);
    obj->follow(1,2);
    obj->postTweet(2,6);
    vector<int> param_2 = obj->getNewsFeed(1);
    println(param_2);
    obj->unfollow(1,2);  
    vector<int> param_3 = obj->getNewsFeed(1);
    println(param_3);
    return 0;
}
