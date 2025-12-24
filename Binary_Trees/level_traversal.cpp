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
     void helper(TreeNode* root, vector<TreeNode*>&level, vector<vector<int>>&result){
         if(level.empty()) return;
         vector<TreeNode*>temp;
         vector<int>vals;
         for(auto ele : level){
             if(ele->left != nullptr){
                 temp.push_back(ele->left);
                 vals.push_back(ele->left->val);
             }
             if(ele->right != nullptr){
                 temp.push_back(ele->right);
                 vals.push_back(ele->right->val);
             }
         }
         level = temp;
         if(!vals.empty())
            result.push_back(vals);
         helper(root,level,result);
     }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        vector<TreeNode*>level;
        if(root != nullptr){
            level.push_back(root);
            result.push_back({root->val});
        }
        helper(root,level,result);
        return result; 
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<vector<int>>result = s.levelOrder(root);
    for(vector<int> ele1 : result){
        for(int ele2 : ele1){
            cout<<ele2<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
