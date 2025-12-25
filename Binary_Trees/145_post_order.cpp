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
public:
    // void helper(TreeNode* root, vector<int>&traversal){
    //     if(root == nullptr) return;
    //     helper(root->left,traversal);
    //     helper(root->right,traversal);
    //     traversal.push_back(root->val);
    // }
    public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>traversal;
        stack<TreeNode*>st1;
        stack<int>st2;
        if(root != nullptr) st1.push(root);
        while(!st1.empty()){
            TreeNode* root = st1.top();
            st1.pop();
            st2.push(root->val);
            if(root->left != nullptr) st1.push(root->left);
            if(root->right != nullptr) st1.push(root->right);
        }
        while(!st2.empty()){
            traversal.push_back(st2.top());
            st2.pop();
        }
        return traversal;    
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int>result = s.postorderTraversal(root);
    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
