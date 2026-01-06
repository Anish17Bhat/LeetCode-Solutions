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
    void helper(TreeNode* root,int row, int col, map<int,multiset<pair<int,int>>>&ans){
        if(root == nullptr) return;

        row++;
        col--;
        helper(root->left,row,col,ans);
        row--;
        col++;


        ans[col].insert({row,root->val});

        row++;
        col++;
        helper(root->right,row,col,ans);
        row--;
        col--;
    }
public:
    vector<int> TopView(TreeNode* root) {
        map<int,TreeNode*>ans;
        // helper(root,0,0,ans);
        int col = 0;
        queue<pair<TreeNode*,int>>q;
        vector<int>result;
        if(!root) return result;
        q.push({root,col});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                auto t = q.front();
                ans[t.second] = t.first;
                q.pop();
                if(t.first->left != nullptr) q.push({t.first->left,t.second-1});
                if(t.first->right != nullptr) q.push({t.first->right,t.second+1});
            }
        }
        for(auto ele : ans){
            result.push_back(ele.second->val);
        }
        return result;
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
        20, 8, 22, 5, 3, 4, 25, nullopt, nullopt, 10 ,14
    };
    TreeNode* root = buildTree(arr);
    vector<int>result = s.TopView(root);
    for(auto ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
