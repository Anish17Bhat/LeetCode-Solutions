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
    int maxSum = INT_MIN;
    int MaxSumFinder(TreeNode* root,int &maxSum){
        if(!root) return 0;
        int leftSum = max(0,MaxSumFinder(root->left,maxSum));
        int rightSum = max(0,MaxSumFinder(root->right,maxSum));

        maxSum = max(maxSum,root->val + leftSum + rightSum);
        return root->val + max(leftSum,rightSum);;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxSum = root->val;
        MaxSumFinder(root,maxSum);
        return maxSum;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);  
    cout<<s.maxPathSum(root)<<endl;
    return 0;
}
