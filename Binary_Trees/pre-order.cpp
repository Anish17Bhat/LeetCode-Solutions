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
    void helper(TreeNode* root, vector<int>&traversal){
        if(root == nullptr) return;
        traversal.push_back(root->val);
        helper(root->left,traversal);
        helper(root->right,traversal);
    }
    public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>traversal;
        helper(root,traversal);
        return traversal;    
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int>result = s.preorderTraversal(root);
    for(int ele : result){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
