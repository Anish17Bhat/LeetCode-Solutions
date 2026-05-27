#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>>result;
    unordered_map<string,int>mp;
    string b;
    int s;
public:

    void dfs(string word , vector<string> &seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            result.push_back(seq);
            reverse(seq.begin(),seq.end());
            return ;
        }
        int steps = mp[word];
            for(int i = 0 ; i < s ; i++){
                char original = word[i];
                for(char c = 'a' ; c <= 'z' ; c++){
                    word[i] = c;
                    if(mp.find(word) != mp.end() && mp[word] + 1 == steps){
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                }
                word[i] = original;
            }

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        b = beginWord;
        st.erase(beginWord);
        q.push({beginWord,1});
        mp[beginWord] = 1;
        s = beginWord.size();
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord)  break;
            for(int i = 0 ; i < s ; i++){
                char original = word[i];
                for(char c = 'a' ; c <= 'z' ; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if(mp.find(endWord) != mp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<string> v = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> result = sol.findLadders("hit","cog",v);    
    for(auto v : result){
        for(string e : v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    return 0;
}
