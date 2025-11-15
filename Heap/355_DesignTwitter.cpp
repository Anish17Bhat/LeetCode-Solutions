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
        vector<int>temp;
        for(auto it = range.first ; it != range.second ; ++it){
            temp.push_back(it->second);
        }
        for(auto ele : tweet){
            if(ele.second.first == userId){
                count++;
                feed.push_back(ele.second.second);
                if(count == 10) return feed;
            }
            else{
                if(find(temp.begin(),temp.end(),ele.second.first) != temp.end()){
                    count++;
                    feed.push_back(ele.second.second);
                    if(count == 10) return feed;
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
    // easy test case
    // Twitter* obj = new Twitter(); obj->postTweet(1,5); vector<int> param_1 = obj->getNewsFeed(1); println(param_1); obj->follow(1,2); obj->postTweet(2,6); vector<int> param_2 = obj->getNewsFeed(1); println(param_2); obj->unfollow(1,2); vector<int> param_3 = obj->getNewsFeed(1); println(param_3);


    Twitter* obj = new Twitter();

    obj->postTweet(1, 6765);
    obj->postTweet(5, 671);
    obj->postTweet(3, 2868);
    obj->postTweet(4, 8148);
    obj->postTweet(4, 386);
    obj->postTweet(3, 6673);
    obj->postTweet(3, 7946);
    obj->postTweet(3, 1445);
    obj->postTweet(4, 4822);
    obj->postTweet(1, 3781);
    obj->postTweet(4, 9038);
    obj->postTweet(1, 9643);
    obj->postTweet(3, 5917);
    obj->postTweet(2, 8847);

    obj->follow(1, 3);
    obj->follow(1, 4);
    obj->follow(4, 2);
    obj->follow(4, 1);
    obj->follow(3, 2);
    obj->follow(3, 5);
    obj->follow(3, 1);
    obj->follow(2, 3);
    obj->follow(2, 1);
    obj->follow(2, 5);
    obj->follow(5, 1);
    obj->follow(5, 2);

    vector<int> f1 = obj->getNewsFeed(1);
    println(f1);

    vector<int> f2 = obj->getNewsFeed(2);
    println(f2);

    vector<int> f3 = obj->getNewsFeed(3);
    println(f3);

    vector<int> f4 = obj->getNewsFeed(4);
    println(f4);

    vector<int> f5 = obj->getNewsFeed(5);
    println(f5);

    return 0;
}
