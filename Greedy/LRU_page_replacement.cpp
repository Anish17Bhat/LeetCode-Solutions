#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    private:
        int time = 0;
        int size = 0;
        int cap = 0;
        map<int,pair<int,int>>lru;
        unordered_map<int,int>mp;
    public:
        LRUCache(int capacity){
            cap = capacity;
        }
        void put(int key , int value){
            if(mp.find(key) != mp.end()){
                int t = mp[key];
                lru.erase(t);
                lru[++time] = {key,value};
                mp[key] = time;
            }
            else{
                if(size < cap){
                    lru[++time] = {key,value};
                    mp[key] = time;
                    size++;
                }
                else{
                    auto ele = *lru.begin();
                    int k = ele.second.first;
                    lru.erase(lru.begin());
                    mp.erase(k);
                    lru[++time] = {key,value};
                    mp[key] = time;
                }
            }
        }
        int get(int key){
            if(mp.find(key) == mp.end()) return -1;
            
            int t = mp[key];
            int value = lru[t].second;
            lru.erase(t);
            lru[++time] = {key,value};
            mp[key] = time;
            return value;
        }
};

int main(){
    LRUCache *l = new LRUCache(2);
    l->put(1,1);
    l->put(2,2);
    cout<<l->get(1)<<endl;
    l->put(3,3);
    cout<<l->get(2)<<endl;
    return 0;
}
