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
    int check(TreeNode* root){
        if(root == nullptr) return 0;
        int lefty = check(root->left);
        if(lefty == -1) return -1;

        int righty = check(root->right);
        if(righty == -1) return -1;

        if(abs(lefty - righty) > 1) return -1;
        return max(lefty,righty) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        return check(root) != -1;
    }
};

int main(){
    Solution s;
                        1
                       / \
                      2   2
                     / \
                    3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    cout<<s.isBalanced(root)<<endl;
    return 0;
}
