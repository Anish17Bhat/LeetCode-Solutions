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
    void helper(TreeNode* root, int &maxDepth, int depth){
        if(root == nullptr){
            maxDepth = max(maxDepth,depth);
            return;
        }
        else depth++;
        helper(root->left,maxDepth,depth);
        helper(root->right,maxDepth,depth);
        depth--;
    }
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        int depth = 0; 
        helper(root,maxDepth,depth); 
        return maxDepth;    
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    cout<<s.maxDepth(root)<<endl;
    return 0;
}
