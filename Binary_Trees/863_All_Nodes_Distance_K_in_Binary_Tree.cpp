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
    void dfs(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent_track){
        queue<TreeNode*>q;
        q.push(root);
        parent_track[root] = nullptr;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* ele = q.front();
                q.pop();
                if(ele->left){
                    q.push(ele->left);
                    parent_track[ele->left] = ele;
                } 
                if(ele->right){
                    q.push(ele->right);
                    parent_track[ele->right] = ele;
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,TreeNode*>parent_track;
       dfs(root,parent_track);
       unordered_map<TreeNode*,bool>visited;
       queue<TreeNode*>q;
       q.push(target);
       visited[target] = true;
       int level = 0;
       while(!q.empty()){
            int size = q.size();
            if(level == k) break;
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
            level++;
       }
       vector<int>ans;
       while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
       }
       return ans;
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
       3,5,1,6,2,0,8,nullopt,nullopt,7,4
    };
    TreeNode* root = buildTree(arr);
    vector<int>ans = s.distanceK(root,root->left,2);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
