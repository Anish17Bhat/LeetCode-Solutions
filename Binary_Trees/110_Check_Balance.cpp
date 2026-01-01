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
    int MaxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + max(MaxDepth(root->left),MaxDepth(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        return abs(MaxDepth(root->left) - MaxDepth(root->right)) > 1 ? false : true;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->left = new TreeNode(4);
    root->right->right->left->right = new TreeNode(4);
    cout<<s.isBalanced(root)<<endl;
    return 0;
}
