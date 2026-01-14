#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution {
    TreeNode* dfs(TreeNode* root, int start){
        if(root == nullptr) return nullptr;
        if(root->val == start) return root;
        TreeNode* lefty = dfs(root->left,start);
        if(lefty) return lefty;
        TreeNode* righty = dfs(root->right,start);
        if(righty) return righty;
        return nullptr;
    }
    void trackParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent_track){
        parent_track[root] = nullptr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* ele = q.front();
                q.pop();
                if(ele->left){
                    parent_track[ele->left] = ele;
                    q.push(ele->left);
                } 
                if(ele->right){
                    parent_track[ele->right] = ele;
                    q.push(ele->right);
                }
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* startNode = dfs(root,start);
        unordered_map<TreeNode*,bool>visited;
        unordered_map<TreeNode*,TreeNode*>parent_track;
        trackParent(root,parent_track);
        queue<TreeNode*>q;
        q.push(startNode);
        visited[startNode] = true;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* ele = q.front();
                q.pop();
                if(ele->left && !visited[ele->left]){
                    q.push(ele->left);
                    visited[ele->left] = true;
                }
                if(ele->right && !visited[ele->right]){
                    q.push(ele->right);
                    visited[ele->right] = true;
                }
                if(parent_track[ele] && !visited[parent_track[ele]]){
                    q.push(parent_track[ele]);
                    visited[parent_track[ele]] = true;
                }
            }
            if(!q.empty()) time++;
        }
        return time;
    }
};

TreeNode* buildTree(const vector<optional<int>>& arr) {
    if (arr.empty() || !arr[0].has_value())
        return nullptr;

    TreeNode* root = new TreeNode(arr[0].value());
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i].has_value()) {
            curr->left = new TreeNode(arr[i].value());
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i].has_value()) {
            curr->right = new TreeNode(arr[i].value());
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main(){
    Solution s;
    vector<optional<int>> arr = {
       1,5,3,nullopt,4,10,6,9,2
    };
    TreeNode* root = buildTree(arr);
    cout<<s.amountOfTime(root,3);
    cout<<endl;
    return 0;
}
