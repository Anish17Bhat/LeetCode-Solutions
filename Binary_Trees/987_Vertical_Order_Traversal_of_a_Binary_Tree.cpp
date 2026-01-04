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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>>ans;
        helper(root,0,0,ans);
        vector<vector<int>>result;
        for(auto ele : ans){
            vector<int>temp;
            for(auto e : ele.second){
                temp.push_back(e.second);
            }
            result.push_back(temp);
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
        3,1,4,0,2,2
    };
    TreeNode* root = buildTree(arr);
    vector<vector<int>>result = s.verticalTraversal(root);
    for(auto ele : result){
        for(int e : ele){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
